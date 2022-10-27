#include "function.h"


/* Global constant variable to intialize the array size and control the loop. */
const int NUM = 10;


/*
 * Part a of the assignment: working with a three digits number and operations.
 */
void part_a() {

    /*
     * Generating a three-degit integer.
     */
    srand(time(0));
    int number = rand() % 900 + 100;

    /* Boolean variable used to control the do-while loop. */
    bool exit = false;      
    
    do {

        /* Print out multiple blank lines. */
        cout << endl << endl << endl;

        char pause;
        int choice, remainder, temp = number;
        int sum = 0, triple = 0, reverse = 0;
        cout << "= ==================================================================== =\n";
        cout << "= Part a - Working with a three digits number and operations.          =\n"; 
        cout << "= ==================================================================== =\n";
        cout << "= The generated number is: " << number << "                                         =\n"; 
        cout << "= 1. Sum the digits.                                                   =\n";
        cout << "= 2. Triple the number.                                                =\n";
        cout << "= 3. Reverse the digits.                                               =\n";
        cout << "= 4. Exit.                                                             =\n";
        cout << "= Please choose one of these operations: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        switch (choice) {
            
            /*
             * REFERENCE: StackOverFlow. How to sum digits from integer in c++? 
             * Source: https://stackoverflow.com/questions/39952421/how-to-sum-digits-from-integer-in-c
             */
            case 1:
                sum = temp/100 + (temp/10)%10 + temp%10;
                cout << "= The result is: " << sum << "!\n"; 
                break;
            
            case 2:
                triple = number*number*number;
                cout << "= The result is: " << triple << "!\n"; 
                break;

            /*
             * REFERENCE: Programiz. C++ Program to Reverse a Number. 
             * Source: https://www.programiz.com/cpp-programming/examples/reverse-number
             */
            case 3:
                while(temp != 0) {
                    remainder = temp%10;
                    reverse = reverse*10 + remainder;
                    temp /= 10;
                }
                cout << "= The result is: " << reverse << "!\n"; 
                break;

            case 4: 
                exit = true;
                break;

            default: cout << "!!! You have entered an invalid number! Please choose 1-3 or 0 to exit. !!!\n";
        }

        /*
         * No need to pause when choice 4 is selected.
         */
        if(choice != 4) {
            cout << "Press any key to continue..";
            cin >> pause;
            cin.ignore();
        }

    } while (!exit);    /* End do-while loop. */
    return;
}


/*
 * Part b of the assignment: working with random numbers and array.
 */
void part_b() {

    cout << "= ==================================================================== =\n";
    cout << "= Part b - Working with random numbers and array.                      =\n"; 
    cout << "= ==================================================================== =\n";
    int list[NUM];
    
    /*
     * Call read_from_afile() function.
     */
    read_from_afile(list);
    
    /*
     * Call sort_array() function.
     */
    sort_array(list);

    return;
}


/*
 * Read data from an external file.
 * Precondition: array of int (unsorted).
 * Postcondition: the input file is successfully open to read.
 *                arr list[] is initialied and stored 10 random numbers.
 */
void read_from_afile(int list[]) {
    
    /* Open input file. */
    ifstream inFile;
    inFile.open("text.txt");

    /* Check the file is open, mean available to read. */
    if (!inFile) {
		cout << "\n*ERROR!* Some errors occur while trying to open input file!\n\n";
	}
	else {
        int index = 0;
		while(!inFile.eof()) {
            inFile >> list[index];
            index++;
        }
	}
    /* Close input file. */
    inFile.close(); 
    return;
}


/*
 * Sort the array.
 * Precondition:  array of int (unsorted).
 * Postcondition: sort the array and print out the sorted array to an external file.
 */
void sort_array(int list[]) {

    /* Open output file. */
	ofstream outfile;
	outfile.open("output.txt");

    /*
     * Call print_number() function. (Before sorting the array)
     */ 
    outfile << "= Print out the numbers in the (unsorted) array list: ";
    print_number(outfile, list);


    /*
     * Sort the array using sort() - built-in function.
     */
    sort(list, list+NUM);

    /*
     * Call print_number() function. (After sorting the array)
     */
    outfile << "= Print out the numbers in the (sorted)   array list: ";
    print_number(outfile, list);

    /* Close output file. */
    outfile.close();

    cout << "= The array is successfully printed in an external file - output.txt!  =\n";
    return;
}


/*
 * Write the array to an external file.
 */
void print_number(ofstream &outfile, int list[]) {

    /* Check the file is open, mean available to write. */
    if (!outfile) {
		cout << "\n*ERROR!* Some errors occur while trying to open output file!\n\n";
	}
    else {
        
        for (int index = 0; index < NUM; index++) {
            outfile << list[index];
            if(index <= 8)
                outfile  << ", ";
        }
        outfile << ".\n";
    }
    return;
}


/*
 * Part c of the assignment: working with enum and string variable.
 * REFERENCE: DelftStack. Convert Enum to String in C++
 * Source: https://www.delftstack.com/howto/cpp/how-to-convert-enum-to-string-cpp/
 */
void part_c() {

    cout << "= ==================================================================== =\n";
    cout << "= Part c - Working with enum and string variable.                      =\n"; 
    cout << "= ==================================================================== =\n";
    cout << "= Guessing dates of the third week of January                          =\n";
    cout << "= The result is: " << left << setw(22);

    /* Generate random input. */
    srand(time(0));
    int random = rand() % Unknown;
    int input = static_cast<Day>(random);

    switch (input) {
        case Monday: 
            cout << enum_str[Monday]; 
            break;

        case Tuesday: 
            cout << enum_str[Tuesday]; 
            break;

        case Wednesday: 
            cout << enum_str[Wednesday]; 
            break;

        case Thursday: 
            cout << enum_str[Thursday]; 
            break;

        case Friday: 
            cout << enum_str[Friday]; 
            break;

        case Saturday: 
            cout << enum_str[Saturday]; 
            break;

        case Sunday: 
            cout << enum_str[Sunday]; 
            break;

        case Unknown: 
            cout << "Incorrect day!" << endl; 
            break;
    }
    cout << "                                =\n";
    return;
}
