#include "card.h"

/* Setters. */
void Card::set_suit(string s) {
    S = s;
    return;
}

void Card::set_rank(string r) {
    R = r;
    return;
}

/* Getters. */
string Card::get_suit() const {
    return S;
}

string Card::get_rank() const {
    return R;
}

/* Overloading operator function. */
bool Card::operator == (const Card& other) const {
    if(S == other.S && R == other.R)
        return true;

    return false;
}
