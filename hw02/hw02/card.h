#ifndef CARD_H_
#define CARD_H_

/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #1      : Deck of Cards
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 1/27/2022
*******************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/* static variables used to initialize the standard size for Suit[] and Rank[]. */
static const int SUIT_SIZE = 4;
static const int RANK_SIZE = 13;

/* Suit. */
/* S: Spades, D: Diamonds; H: Hearts; C: Clubs. */
const string Suit[SUIT_SIZE] = {"S", "D", "H", "C"};

/* Rank. */
/* 1: Ace; 13: King; 12: Queen; 11: Jack. */
const string Rank[RANK_SIZE] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};

class Card {

public:

    /* Default constructors. 
     * *******************************************************************************
     * Pre-condition: <none>
     * Post-condition : each new object is initialized.
     */
    Card() {}

    /* Destructor. 
     * *******************************************************************************
     * Pre-condition: <none>
     * Post-condition : all created objects are deleted before terminating the program.
     */
    ~Card() {}

    /* Setter functions. 
     * *******************************************************************************
     * Pre-condition: string variable.
     * Post-condition : object S and R are assigned to the parameters.
     */
    void set_suit(string);
	void set_rank(string);

    /* Getter functions. 
     * *******************************************************************************
     * Pre-condition: <none>
     * Post-condition : return object S and R.
     */
	string get_suit() const;
	string get_rank() const;

    /* Function to compare 2 cards in a deck.
     * To determine if 2 cards are identical iff both their suit and rank match.
     * *******************************************************************************
     * Pre-condition: object other.
     * Post-condition : return true if 2 cards match; otherwise, return false.
     */
    bool operator == (const Card& other) const;

private:

    string S;
    string R;
};

#endif /* CARD_H_ */
