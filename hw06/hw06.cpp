/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #6      : Recursion
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 02/24/2022
*******************************************************************************************
 * Purpose: Getting familiar with recursion in C++.     
*******************************************************************************************
 * IO:
 * // print out output from recursive calls.
 * // first reverse letters: 12-19.
 * // second reverse letters: 5-23.
 * // last reverse letters: the entire alphabet.
*******************************************************************************************
 * Question: What are the differences between the recursive and iterative approaches?
 * Eventhough they produce the same result, 
 * in recursive approach, the function calls itself until the condition is met, whereas,
 * in iterative approach, a function repeats until the condition fails.
*******************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


namespace recursion {

    /*
     * (Recursive) function to reverse the letters in range begin-end.
     * Pre-condition: string and in variables.
     * Post-condition: char from 'begin' index to 'end' index are reversed.
     */
    void reverse_recursive(const string& original, int begin, int end) {

        if(end >= begin) {
            cout << original[end];
            reverse_recursive(original, begin, (end-1));
        }
        return;
    }

    /*
     * (Interative) function to reverse the letters in range begin-end.
     * Pre-condition: string and in variables.
     * Post-condition: char from 'begin' index to 'end' index are reversed.
     */
    void reverse_iterative(const string& original, int begin, int end) {

        while(end >= begin) {
            cout << original[end];
            end -= 1;
        }
        return;
    }
}   // end recursion{}

/* main() program. */
int main() {

    /* Original string. */
    string original{"abcdefghijklmnopqrstuvwxyz"};

    /* int variables hold begin and end indices. */
    int begin, end;

    /* Temp variable to control the loop. Terminate the loop when true */
    bool exit = false;

     /* Print out the original string. */
    cout << "= The original string is: ";
    for(int i=0; i < (int)original.length(); i++)
        cout << original[i];
    cout << endl;

    /* while exit holds not-true. */
    while(!exit) {

        cout << "= Calling reverse(). Please enter the indices for begin and end: \n";
        cin >> begin >> end;

        /* Use the recursive function. */
        cout << "= Reverse letters (using recursive function) [" << begin << "-" << end << "]: ";

        /* Print out the first part (from 0 to begin index) of the string. */
        for(int i=0; i < begin; i++)
            cout << original[i];

        recursion::reverse_recursive(original, begin, end);

        /* Print out the rest (start with end index) of the string. */
        for(int i=end+1; i < (int)original.length(); i++)
            cout << original[i];
        cout << endl;

        /* Use the iterative function. */
        cout << "= Reverse letters (using iterative function) [" << begin << "-" << end << "]: ";

        /* Print out the first part (from 0 to begin index) of the string. */
        for(int i=0; i < begin; i++)
            cout << original[i];

        recursion::reverse_iterative(original, begin, end);

        /* Print out the rest (start with end index) of the string. */
        for(int i=end+1; i < (int)original.length(); i++)
            cout << original[i];
        cout << endl;

        /* If the user wants to run another round. */
        cout << "= Continue? (y/n) ";
        char another;
        cin >> another;
        cout << endl;

        /* Check if the user enters an invalid input. */
        while(another != 'y' && another != 'Y' && another != 'n' && another != 'N') {
            cout << "= Invalid input!! Please enter y/Y for yes or n/N for no!\n";
            cout << "= Continue? (y/n) ";
            cin >> another;
        }

        /* If the user wants to end the loop. */
        if(another == 'n' || another == 'N')
            exit = true;
    }
    
    cout << "= Terminating the program!\n";
    return 0;
}
