/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #7      : Pointers & Dynamic Arrays 
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 01/03/2022
*******************************************************************************************
 * Purpose: Getting familiar with Pointers & Dynamic Arrays in C++. 
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

#include "ManageInventory.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

/* main() program. */
int main() {

    /* Intro. */
    cout << "= WELCOME! Please enter your name for this purhcase: ";
    string name;
    getline(cin, name);

    /* Set up the format for float or double number like 29.99. */
    cout << fixed << showpoint << right << setprecision(2); 

    /* Temp variables to temporarily hold private data members. */
    bool exit = false;
    int choice = -1;
    char another_item;

    /* Load the inventory - dynamic array. */
    ManageInventory *items = new ManageInventory;
    
    /* Add items. */
    items->addItem();

    /* Instance using copy constructor. */
    ManageInventory *copy_of_items;
    copy_of_items = items;

    /* Displaying the menu. */
    int *cart = new int[TOTAL_ITEMS];          /* Dynamically alocated array for shopping cart - store indices.   */
    int *quan_wants = new int[TOTAL_ITEMS];     /* Dynamically alocated array for the desired quanity for an item. */
    int need = 0;

    /* Base case. */
    for(int i = 0; i < TOTAL_ITEMS; i++) {
        cart[i] = -1;
        quan_wants[i] = -1;
    }
    
    do {

        system("clear");
        cout << "= For " << name << endl;
        cout << "= ======================================================================================================== =\n";
        cout << left << "= Items number =" << setw(57) << "  Name of Equipment:                    " << "=    Cost:   =" << setw(22) << "  Current quanity:  =\n";
        
        cout << *copy_of_items;   /* Instead of using the original one, the copy object can also be used. */
    
        cout << "= -------------------------------------------------------------------------------------------------------- =\n";
        cout << "= Enter 0 to cancel this transaction and exit the menu!                                                    =\n";
        cout << "= ======================================================================================================== =\n";
        cout << "= Please pick an item (0-5) and the quanity for that item..                                                =\n";
        cout << "= For item: ";
        cin >> choice;
        cin.ignore(1000, '\n'); 
        
        /* The user wants to exit the menu. */
        if(choice == 0) {

            cout << "= Exiting the menu...\n";
            exit = true;
            break;

        }
        else {

            /* Check the input. */
            while(choice < 0 || choice > 10) {
                cout << setw(104) << "= You have entered an invalid choice. Please enter a number in the range 0-5." << "=" << endl << endl;
            }

            /* Ask for how many. */
            cout << "= For quanity: ";
            cin >> need;
            cin.ignore(1000, '\n'); 

            /* Check if the item's quanity is less than what the costumer wants. */
            if(need > items->get_quanity(choice-1)) {
                cout << setw(104) << "= The item's quanity is not enough. The item's current quanity will be added to the cart instead!" << "=\n";
                need = items->get_quanity(choice-1);
            }

            /* Print out the message. */
            cout << "= " << need << " " << items->get_item(choice-1) << "(s) are added to the cart!\n"; 

            /* Store the transaction into the shopping cart array. */
            cart[choice-1] = choice-1;         /* indices. */
            quan_wants[choice-1] = need;       /* quanities. */

            
            /* Check if the customer wants to buy another item. */
            cout << "= Do you want to add another item into your cart? (y/Y or n/N): ";
            cin >> another_item;
            cin.ignore(1000, '\n'); 

            /* Check the input. */
            while(another_item != 'n' && another_item != 'N' && another_item != 'y' && another_item != 'Y') {
                cout << "You have entered an invalid choice. Please enter y/Y for yes or n/N for no." << endl << endl;
            }

            /* If the user wants to make a purchase. */
            if(another_item == 'N' || another_item == 'n') {

                reciept(items, cart, quan_wants, name);
                exit = true;
                break;

            }
        }
    } while(!exit);

    /* The inventory after the purchase. */
    system("clear");
    cout << setw(107) << "= The inventory is updated..." << "=\n";
    cout << "= ======================================================================================================== =\n";
    cout << left << "= Items number =" << setw(57) << "  Name of Equipment:                    " << "=    Cost:   =" << setw(22) << "  Current quanity:  =\n";
    cout << *items;  
    cout << "= ======================================================================================================== =\n";
    
    /* Deleting all dynamically alocated variables/arrays. */ 
    delete [] cart;
    delete [] quan_wants;
    
    delete items;

    cout << "= Terminating the program!\n";
    return 0;
}
