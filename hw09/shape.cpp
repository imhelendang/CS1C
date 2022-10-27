#include "shape.h"

Shape::~Shape() {}

/* Setters. */
void Shape::set_x(int temp_x) {
    x = temp_x; 
}

void Shape::set_y(int temp_y) {
    y = temp_y; 
}

/* Getters. */
int Shape::get_x() const {
    return x;
}

int Shape::get_y() const { 
    return y;
}