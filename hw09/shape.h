#ifndef SHAPE_H_
#define SHAPE_H_

/******************************************************************************************
 * AUTHOR     : Jade Tran
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
*******************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

class Shape { 
public: 
    Shape() { x = 0; y = 0; }
    Shape(int x, int y) : x{x}, y{y} { } 
    virtual ~Shape() = 0;   /* Virtual destructor. */

    /* Setters.
     * Pre-condition: int variables.
     * Post-condition: private member variables must be assigned to valid variables.
     */
    void set_x(int temp_x);
    void set_y(int temp_y);

    /* Getters.
     * Pre-condition: <none>
     * Post-condition: return all the object's private data accoridng to the function.
     */	
    int get_x() const;
    int get_y() const;

    /* Pure Virtual Functions. */
    virtual int calcPerimeter() const = 0;
    virtual int calcArea() const = 0;

    virtual void print() = 0;

private: 
    int x; // x-coordinate 
    int y; // y-coordinate 
}; 
 
#endif /* SHAPE_H_ */

