/************************************************************************
 * AUTHOR     : Jade Tran
 * HW #1      : Random Numbers
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 1/25/2022
*************************************************************************
 * Purpose: review old concepts from CS1B class. 
 * Part a:  Write a program that uses a random number generator to 
 *          generate a three-digit integer that allows the user to 
 *          perform the following operations.
 * Part b:  Write a function to read data from a file and then store
 *          that data (10 random numbers) into an array. Then, sort the
 *          array and write the array to an external file by calling a
 *          function.
 * Part c:  Write a function to randomly generate an int, 1 - Monday,
 *          2 - Tuesday, and so on. Then, by using enum, output the date
 *          of that day in the third week of January.
*************************************************************************
 * IO:
 * = ==================================================================== =
 * = Part a - Working with a three digits number and operations.          =
 * = ==================================================================== =
 * = The generated number is: 109                                         =
 * = 1. Sum the digits.                                                   =
 * = 2. Triple the number.                                                =
 * = 3. Reverse the digits.                                               =
 * = 4. Exit.                                                             =
 * = Please choose one of these operations: (the user enter choice here).
 * = ==================================================================== =
 * = Part b - Working with random numbers and array.                      =
 * = ==================================================================== =
 * = The array is successfully printed in an external file - output.txt!  =
 * = ==================================================================== =
 * = Part c - Working with enum and string variable.                      =
 * = ==================================================================== =
 * = Guessing dates of the third week of January                          =
 * = The result is:                                                       =
 * = Terminating the program!                                             =
 * = ==================================================================== =
*************************************************************************/

#include "function.h"
using namespace std;


/* Main program. */
int main() {

    /*
     * Part a of the assignment.
     */
    part_a();

    /*
     * Part b of the assignment.
     */
    part_b();

    /*
     * Part c of the assignment.
     */
    part_c();
    
    cout << "= Terminating the program!                                             =\n";
    cout << "= ==================================================================== =\n";
    return 0;

}
