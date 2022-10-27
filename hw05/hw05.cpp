/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #5      : STL Vectors
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 02/17/2022
*******************************************************************************************
 * Purpose: Getting familiar with STL and vvectors in general.     
*******************************************************************************************
 * IO:
 * 
 * 
 * 
*******************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>    // std::random_shuffle
#include <random>       // std::random_device
using namespace std;

/* Constant int variables to initialize the begining of the range. */
const int RANGE_BEGIN = 1;

namespace lott {

    /* Function definitions:
    * ******************************************************************************************/

    /* random generator builtin function. */
    std::random_device rd;
    std::mt19937 g(rd());

    /*
     * lotto() function 
     * Pre-condition: int variables.
     * Post-condition: return a vector<int> object that contains, in sorted order, the numbers selected at random.
     */
    vector<int> lotto(int& spotsOnCard, int& numSpots) {

        /* Temporary vectors. */
        vector<int> result, range;

        std::srand ( unsigned ( std::time(0) ) );

        /* Set some values - the initial range (1-51). */
        for (int i=RANGE_BEGIN; i<spotsOnCard; ++i) {
            result.push_back(i);
            range.push_back(i-1);
        } 

        /* Randomly shuffle the numbers and range.
         * NOTE: NO duplicates.
         */
        shuffle(result.begin(), result.end(), g);
        shuffle(range.begin(), range.end(), g);

        /* Create vector winner store the winner's numbers. */
        vector<int> winner;
        for(int i = 0; i < numSpots; i++) {
            winner.push_back(result[range[i]]);
        }

        /* Sort the numbers. */
        sort(winner.begin(), winner.end());

        result.clear();
        range.clear();

        return winner;
    }
}

/* main() program. */
int main() {

    int num_selected = 6;
    int spots_on_card = 51;
    vector<int> winners;
    winners = lott::lotto(spots_on_card, num_selected); 

    /* Iterate through the array and print out each element. */
    cout << "= !!!WELCOME TO THE LOTTERY CARD GAME!!! " << endl;
    cout << "= The winner of this lottery card game is: ";
    for (std::vector<int>::iterator it=winners.begin(); it!=winners.end(); ++it)
    std::cout << ' ' << *it;

    cout << "\n= Terminating the program!\n";
    return 0;
}
