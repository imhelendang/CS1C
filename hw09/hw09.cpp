/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #9      : Virtual Functions & Abstract Classes 
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 03/15/2022
*******************************************************************************************
 * Purpose: Getting familiar with Virtual Functions & Abstract Classes.
******************************************************************************************* 
 * To run: make
 *         ./hw07
 * To check all possible memroy leaks: 
 *         valgrind --leak-check=full ./hw07
*******************************************************************************************
 * IO:
 * Print out the main menu - displaying all items, quanities, and prices.
 * Print out the reciept.
*******************************************************************************************/

#include "shape.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

namespace hw09 {

    /* Function definition. */
    /*
     * void print function.
     * Function for calling the internal class member function then output the result for each object's perimeter.
     * Pre-condition: Triangle and Rectangle objects.
     * Post-condition: <none>
     */
    void printPerimeter(Shape*& triangle_object, Shape*& rectangle_object) {

        /* Call class member functions to calculate perimeter for the two objects. */
        cout << "= Calling calcPerimeter(): " << endl;
        cout << "= The triangle's perimeter is: " << triangle_object->calcPerimeter() << endl;
        cout << "= The rectangle's perimeter is: " << rectangle_object->calcPerimeter() << endl;
        
        return;
    }

    /*
     * void print function.
     * Function for calling the internal class member function then output the result for each object's area.
     * Pre-condition: Triangle and Rectangle objects.
     * Post-condition: <none>
     */
    void printArea(Shape*& triangle_object, Shape*& rectangle_object) {

        /* Call class member functions to calculate area for the two objects. */
        cout << "= Calling calcArea(): " << endl;
        cout << "= The triangle's area is: " << triangle_object->calcArea() << endl;
        cout << "= The rectangle's area is: " <<  rectangle_object->calcArea() << endl;

        return;
    }
}   /* end namespace. */


/* main() program. */
int main() {
    
    Shape* triangle_object = new Triangle(3,4,5);
    Shape* rectangle_object = new Rectangle(7,9);

    /* Call the two non-member functions. */
    triangle_object->print();
    rectangle_object->print();
    hw09::printPerimeter(triangle_object, rectangle_object);
    hw09::printArea(triangle_object, rectangle_object);

    /* Clean up. */
    delete triangle_object;
    delete rectangle_object;

    return 0;
}
