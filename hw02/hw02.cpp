/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #1      : Deck of Cards
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 1/27/2022
*******************************************************************************************
 * Purpose: Write a class that will represent a card in a standard deck of 
 *          playing cards.  You will need to represent both the suit 
 *          (clubs, diamonds, hearts or spades) as well as the rank 
 *          (A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2) of each card.   
 *          Then:
 *          Print out the initial of the deck after 
 *          the first perfect shuffle, and the final deck. 
 *          Print out how many perfect shuffles are necessary 
 *          to return the deck to its original configuration.  
 * NOTE: 
 *          In a perfect shuffle, the deck is broken exactly in half 
 *          and rearranged so that the first card is followed by the 27th card, 
 *          followed by the second card, followed by the 28th card, and so on. 
*******************************************************************************************
 * IO:
 *          = Print format starts from index 0, and prints from the left to the right!
 *          =
 *          = The deck after the first perfect shuffle: (print out the initial)
 *          =
 *          = ? perfect shuffles are necessary to return the deck to its original configuration.
 *          =
 *          = The final deck: (print out the initial)
 *          =
 *          = Terminating the program.
 *          = Successfully delete the deck of card!
 *          = Successfully delete the deck of card!
*******************************************************************************************/

#include "cDeck.h"
#include "card.h"
using namespace std;  

/* Main program. */
int main() {

    cDeck original;          /* The original deck - used to compare with the shuffled deck. */
    int count = 1;           /* int variable used to count number of shuffles needed. */

    /* Vector array to contain the indices. */
    vector<int> index;
    for(int i = 0; i < DECK_SIZE; i++) 
        index.push_back(i);

    /* Create deck objects. */
    cDeck d;

    d.perfect_shuffle(index);

    /* Print out the deck after the first shuffle. */
    cout << "= Print format starts from index 0, and prints from the left to the right!";
    cout << "\n=\n= The deck after the first perfect shuffle: " << endl;
    d.print_deck(index);

    while(d.compare_decks(original, index) == false) {
        d.perfect_shuffle(index);
        count++;
    }
    
    /* Print out the message! */
    cout << "=\n= " << count << " perfect shuffles are necessary to return the deck to its original configuration.\n";

    /* Print out the deck after the first shuffle. */
    cout << "=\n= The final deck: " << endl;
    d.print_deck(index);

    /* Print out the message! */
    cout << "=\n= Terminating the program.\n=\n";
    return 0;
}
