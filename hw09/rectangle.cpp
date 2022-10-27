#include "rectangle.h"

/* Setters. */
void Rectangle::set_l(int temp_l) {
    l = temp_l;
}

void Rectangle::set_w(int temp_w) {
    w = temp_w;
}
	
/* Getters. */
int Rectangle::get_l() const {
    return l;
}

int Rectangle::get_w() const {
    return w;
}

/* Additional Functions. */
int Rectangle::calcPerimeter() const {
    return 2 * (get_l() + get_w());
}
  
int Rectangle::calcArea() const {
    return get_l() * get_w();
}

/* Print Function. */
void Rectangle::print() {
    cout << "= The rectangle has length of " << get_l() << " and width of " << get_w() << endl;
    return;
}