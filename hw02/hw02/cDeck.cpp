#include "cDeck.h"
#include "card.h"

/* Constructor. */
cDeck::cDeck() {

    /* int variable used to advance to the next position in array. */
    int count = 0;  

    for (int s = 0; s < SUIT_SIZE; s++) {
        for (int v = 0; v < RANK_SIZE; v++) {
            cards[count].set_suit(Suit[s]);
            cards[count].set_rank(Rank[v]);
            count++;    /* Increase by one after one card is initialized. */ 
        }           
    }
}

/* Destructor. */
cDeck::~cDeck() {
    cout << "= Successfully delete the deck of card!" << endl;
}

/* Function to perform the perfect shuffle. */
void cDeck::perfect_shuffle(vector<int>& index) {
    
    int size = DECK_SIZE/2;

    vector<int> first;
    vector<int> second;

    for(int i = 0; i < size; i++) {
        first.push_back(index[i]);
        second.push_back(index[i+size]);
    }

    /* Reset the vector array. */
    index.clear();

    /* Start shuffling the deck. */
    for(int i = 0; i < size; i++) {
        index.push_back(first[i]);
        index.push_back(second[i]);
    }

    /* Reset the vector arrays. */
    first.clear();
    second.clear();

    return;
}

/* Function to print the deck. */
void cDeck::print_deck(vector<int>& index) {

    int i = 0;
    /* Print the deck nicely. */
    while(i < DECK_SIZE) {

        /* int variable used to advance to control the loop. */
        int count = 0;

        cout << "= " << setw(2) << cards[index[i]].get_rank() << cards[index[i]].get_suit() << "       ";
        i++;
        while(count <= 2) {
            cout << setw(2) <<  cards[index[i]].get_rank() << cards[index[i]].get_suit() << "       ";
            i++;
            count++;
        }
        cout << endl;
    }


    return;
}

/* Function to compare 2 decks of cards. ??????????*/
bool cDeck::compare_decks(const cDeck& original, vector<int>& index) {

    for(int i = 0; i < DECK_SIZE; i++) {
        if(cards[index[i]] == original.cards[i])
            continue;
        else 
            return false;
    }

    return true;;
}
