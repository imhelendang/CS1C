#ifndef MANAGE_INVENTORY_H_
#define MANAGE_INVENTORY_H_

/******************************************************************************************
 * AUTHOR     : Jade Tran
 * HW #7      : Pointers & Dynamic Arrays 
 * CLASS      : CS 1C
 * SECTION    : TTh 12:30 - 2:50
 * DUE DATE   : 01/03/2022
*******************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

const float TAX = 0.0825;
const int TOTAL_ITEMS = 5;

struct Item { 
    string item;
    double price;
    int quanity;
}; 

/* class type ManageInventory. */
class ManageInventory {

private:
    int size {TOTAL_ITEMS}; 
    int count;
    Item** p_pInventoryItems; 

public:
    /* Default constructor. */
    ManageInventory() { 
        count = 0;
        p_pInventoryItems = new Item*[size]; 
        for(int i = 0; i < size; i++) {
            p_pInventoryItems[i] = NULL;
        }
    }

    /* Constructor with parameters. */
    ManageInventory(int size) : size{size}, count{0}, p_pInventoryItems {new Item*[size]} { } 

    /* Copy constructor. */
    ManageInventory(const ManageInventory& copied_item);

    /* Destructor. */
    ~ManageInventory();

    /* Getters.
     * Pre-condition: <none>
     * Post-condition: return all the object's private data accoridng to the function.
     */	
    string get_item(int index) const;
	double get_price(int index) const;
    int get_quanity(int index) const;

    /* addItem().
     * Pre-condition: <none>
     * Post-condition: create a new item and add it to the inventory.
     */	
    void addItem(); 

    /* Function to update the quanity after each purchase
     * Pre-condition: int
     * Post-condition: quanity is updated by subtract number of purchased item.
     */
    //void update_quanity(int number_purchased);

    /* void function to print out the reciept.
     * Pre-condition: class object, arrays of int.
     * Post-condition: List all the items in the cart array .
     */
    friend void reciept(ManageInventory *items, int cart[], int quan_wants[], string name);

    /* Overloading the operators.
     * Pre-condition: ostream, class object (passed by reference).
     * Post-condition: similar to print function but only can be used by employee type object.
     */	
    friend ostream & operator<<(ostream& os, const ManageInventory& other);

};


#endif /* MANAGE_INVENTORY_H_ */
