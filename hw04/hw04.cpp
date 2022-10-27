/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #4      : Friend Functions & Operator Overloading
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 02/10/2022
*******************************************************************************************
 * Purpose: Working with Friend Functions & Operator Overloading.
 *          Getting familiar with class, class data member, and class operations.
*******************************************************************************************
 * IO:
 * // print out test results for the friend & member functions from steps 1, 3.
 * // print out test results for the overloaded operators from steps 2, 4, 5.
 * // For more details, view output.txt for old data, or 
 *                           newOutput.txt for new or updated data.
*******************************************************************************************/

#include "employee.h"
#include "programmer.h"
#include "software.h"
#include "date.h"
using namespace std;  

const int SIZE = 5; /* Constant int variable to initialize each object's size. */

/* Main program. */
int main() {

    /* Create objects. 1 - with default constructor, 2 - with non-default constructor. */
    employee em[SIZE];
    programmer prog[SIZE];
    software soft[SIZE];    

    /* Open input file. */
    ifstream inFile;
    inFile.open("text.txt");

    /* Check the file is open, mean available to read. */
    if (!inFile) {
		cout << "\n*ERROR!* Some errors occur while trying to open input file!\n\n";
	}
	else {

        /* When who == 1, it means the data about to be read is for employee type object; 
                        for programmer type object when who == 2; else, for software type object. */        
        int who;    

        /* Temporary variables used to advance to the next object in an array. */
        int e = 0, p = 0, s = 0;

        /* Keep reading from a file when it hasn't reached the end of the file and e, p, s are in the valid range. */
		while(!inFile.eof() && e <= SIZE && p <= SIZE && s <= SIZE) {
            inFile >> who;
            inFile.ignore(1000, '\n');
            if(who == 1) {
                inFile >> em[e];
                e++;
            }
            else if(who == 2) {
                inFile >> prog[p];
                p++;
            }
            else if(who == 3) {
                inFile >> soft[s];
                s++;
            }
        }
	}
    /* Close input file. */
    inFile.close(); 

    /* Open input file. */
    ofstream outFile;
    outFile.open("output.txt");

    /* Check the file is open, mean available to write. */
    if (!outFile) {
		cout << "\n*ERROR!* Some errors occur while trying to open output file!\n\n";
	}
	else {

        /* *************************************************************************************************************** */
        /*                                              Employees' information.                                            */
        /* *************************************************************************************************************** */    
        outFile << "= ==========================================OLD DATA================================================== =\n";
        outFile << "= ==================================================================================================== =\n";
        outFile << left << setw(103) << "= CS1C EMPLOYEES:" << "=" << endl;
        outFile << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        outFile << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        outFile << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            outFile << em[i];
            outFile << "\n=                                                                                                      =";
        }

        /* *************************************************************************************************************** */
        /*                                           Programmers' information.                                             */
        /* *************************************************************************************************************** */
        outFile << "\n= ==================================================================================================== =\n";
        outFile << left << setw(103) << "= PROGRAMMERS:" << "=" << endl;
        outFile << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        outFile << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        outFile << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            prog[i].print_employee(outFile);
            outFile << "\n=                                                                                                      =";
        }
        
        /* Display the content. */
        outFile << endl << left << setw(18) << "= Name: " << setw(16) << "Department: " << setw(23) << "Supervisor’s Name: "
            << setw(11) << "Raise %: " <<  setw(15) << "C++ Knowledge: " << setw(17) << "Java Knowledge:       =" << endl;
        outFile << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            outFile << prog[i];
            outFile << "\n=                                                                                                      =";
        }

        /* *************************************************************************************************************** */
        /*                                       Software Architectures' information.                                      */
        /* *************************************************************************************************************** */
        outFile << "\n= ==================================================================================================== =\n";
        outFile << left << setw(103) << "= Software Architects :" << "=" << endl;
        outFile << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        outFile << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        outFile << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            soft[i].print_employee(outFile);
            outFile << "\n=                                                                                                      =";
        }
        
        /* Display the content. */
        outFile << left << setw(19) << "\n= Name: " << setw(16) << "Department: " << setw(23) << "Supervisor’s Name: "
            << setw(11) << "Raise %: " <<  setw(35) << "Years of Experience:                 =" << endl;
        outFile << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            outFile << soft[i];
            outFile << "\n=                                                                                                      =";
        }
        
        outFile << "\n= ==================================================================================================== =\n";
	}

    /* Close output file. */
    outFile.close(); 
    cout << "= All information's been entered. To verify, check output.txt file!\n\n";

    
    /* Compare phone employee's phone number. */
    for(int i = 0; i < SIZE; i++) {
        for(int x = 0; x < SIZE; x++) {

            /* With programmer's phone number. */
            compare_phone(em[i], prog[x].get_phone());

            /* With another employee's phone number. */
            if(em[i] == em[x] && i != x) {
                int choice;
                cout << "= " << em[i].get_name() << " and " << em[x].get_name() << " have the same phone number that is: " << em[i].get_phone() <<"\n";
                cout << "= Please choose either one of the employees to change the phone number!\n";
                cout << "= To change " << em[i].get_name() << "'s enter " << i << "; else, enter " << x << " to change " << em[x].get_name() << "'s. ";
                cin >> choice;
                cin.ignore(1000, '\n');

                /* When the user enter an invalid choice, "choice" is neither i nor x. */
                while(choice != i && choice != x) {
                    cout << "!!!!! YOU HAVE ENTERED AN INVALID CHOICE !!!!!\n";
                    cout << "= To change " << em[i].get_name() << "'s enter " << i << "; else, enter " << x << " to change " << em[x].get_name() << "'s. ";
                    cin >> choice;
                    cin.ignore(1000, '\n');
                }

                if(choice - i == 0) {
                    cout << "= Changing " << em[i].get_name() << "'s phone number. Please update his/her number: ";
                    change_phone(em[i]);
                    cout << "\n= Successfully update phone number!\n";
                }
                else if(choice - x == 0) {
                    cout << "= Changing " << em[x].get_name() << "'s phone number. Please update his/her number: ";
                    change_phone(em[x]);
                    cout << "\n= Successfully update phone number!\n";
                }
            }
        }
    }

    /* Updating the employee age. */
    int add = 0, i = 0;
    cout << "= Updating one of the employees to update their age.\n= Please enter: ";
    while(i < SIZE) {
        cout << "[" << i << "] for " << em[i].get_name();
        if(i < SIZE - 1)
            cout << " or ";
        i++;
    }
    cout << ".\n";
    i = 0;
    cin >> i;
    cin.ignore(1000, '\n');
    cout << "= Please enter a number to add: ";
    cin >> add;
    cin.ignore(1000, '\n');

    /* Call update_age() function to update the employee age. */
    update_age(em[i], add);

    /* Open input file. */
    ofstream os;
    os.open("newOutput.txt");

    /* Check the file is open, mean available to write. */
    if (!os) {
		cout << "\n*ERROR!* Some errors occur while trying to open output file!\n\n";
	}
	else {
        
        /* *************************************************************************************************************** */
        /*                                              Employees' information.                                            */
        /* *************************************************************************************************************** */    
        os << "= ==========================================NEW DATA================================================== =\n";
        os << "= ==================================================================================================== =\n";
        os << left << setw(103) << "= CS1C EMPLOYEES:" << "=" << endl;
        os << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        os << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        os << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            os << em[i];
            os << "\n=                                                                                                      =";
        }

        /* *************************************************************************************************************** */
        /*                                           Programmers' information.                                             */
        /* *************************************************************************************************************** */
        os << "\n= ==================================================================================================== =\n";
        os << left << setw(103) << "= PROGRAMMERS:" << "=" << endl;
        os << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        os << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        os << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            prog[i].print_employee(os);
            os << "\n=                                                                                                      =";
        }
        
        /* Display the content. */
        os << endl << left << setw(18) << "= Name: " << setw(16) << "Department: " << setw(23) << "Supervisor’s Name: "
            << setw(11) << "Raise %: " <<  setw(15) << "C++ Knowledge: " << setw(17) << "Java Knowledge:       =" << endl;
        os << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            os << prog[i];
            os << "\n=                                                                                                      =";
        }

        /* *************************************************************************************************************** */
        /*                                       Software Architectures' information.                                      */
        /* *************************************************************************************************************** */
        os << "\n= ==================================================================================================== =\n";
        os << left << setw(103) << "= Software Architects :" << "=" << endl;
        os << "= ==================================================================================================== =\n";
        
        /* Display the content. */
        os << left << setw(18) << "= Name: " << setw(16) << "Employee's Id: " << setw(15) << "Phone: " 
            << setw(6) << "Age: " << setw(9) << "Gender: " << setw(15) << "Job Title: " << setw(13) << "Salary: " 
            << setw(11) << "Hire Date: =" << endl;
        os << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            soft[i].print_employee(os);
            os << "\n=                                                                                                      =";
        }
        
        /* Display the content. */
        os << left << setw(19) << "\n= Name: " << setw(16) << "Department: " << setw(23) << "Supervisor’s Name: "
            << setw(11) << "Raise %: " <<  setw(35) << "Years of Experience:                 =" << endl;
        os << "= ---------------------------------------------------------------------------------------------------- =";
        for(int i = 0; i < SIZE; i++) {
            
            os << soft[i];
            os << "\n=                                                                                                      =";
        }
        
        os << "\n= ==================================================================================================== =\n";
	}

    /* Close output file. */
    os.close(); 
    cout << "\n= All information's been updated. To verify, check newOutput.txt file!\n";
    
    cout << "\n= Terminating the program!\n";
    return 0;
}

