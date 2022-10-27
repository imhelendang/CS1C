#ifndef CDECK_H_
#define CDECK_H_
#include "card.h"

/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #1      : Deck of Cards
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 1/27/2022
*******************************************************************************************/

/* Size of the deck. */
static const int DECK_SIZE = 52;

class cDeck {

public:

    /* Default constructor. 
     * *******************************************************************************
     * Pre-condition: <none>
     * Post-condition : each new object is initialized.
     */
    cDeck();

    /* Destructor. 
     * *******************************************************************************
     * Pre-condition: <none>
     * Post-condition : all created objects are deleted before terminating the program.
     */
    ~cDeck();

    /* Function to perform the perfect shuffle. 
     * Approach: working with indices.
     * *******************************************************************************
     * Pre-condition: vector int index (passed by reference).
     * Post-condition : the deck is broken exactly in half and rearranged 
     *                 so that the first card is followed by the 27th card, 
     *                 followed by the second card, s
     *                 followed by the 28th card, and so on. 
     */
    void perfect_shuffle(vector<int>& index);

    /* Function to print the deck. 
     * *******************************************************************************
     * Pre-condition: vector int temp.
     * Post-condition : print out the initial of the deck (original or shuffled state).
     */
    void print_deck(vector<int>& temp);

    /* Function to compare 2 decks of cards.
     * To accomplish this task: call the overloading operator == in Card class 
     *                          to compare each card, until reach the last card.
     * *******************************************************************************
     * Pre-condition: object d and object original (const).
     * Post-condition : return true if all cards match; otherwise, return false.
     */
    bool compare_decks(const cDeck& original, vector<int>& index);

private:

    /* Composed data member. */
    /* Card object array size 52. */
    Card cards[DECK_SIZE];
};

#endif /* CDECK_H_ */
