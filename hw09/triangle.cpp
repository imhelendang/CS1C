#include "triangle.h"

/* Setters. */
void Triangle::set_a(int temp_a) {
    a = temp_a;
}

void Triangle::set_b(int temp_b) {
    b = temp_b;
}

void Triangle::set_c(int temp_c) {
    c = temp_c;
}

/* Getters. */
int Triangle::get_a() const {
    return a;
}

int Triangle::get_b() const {
    return b;
}

int Triangle::get_c() const {
    return c;
}

/* Additional Functions. */
int Triangle::calcPerimeter() const {
    return get_a() + get_b() + get_c();
}
  
int Triangle::calcArea() const {

    int s = calcPerimeter()/2;
    int area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

/* Print Function. */
void Triangle::print() {
    cout << "= The triangle has sides of length, respectfully, " << get_a() << " and " << get_b() << " and " << get_c() << endl;
    
    return;
}
