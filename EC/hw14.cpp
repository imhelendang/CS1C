/*************************************************************************
 * AUTHOR     : Jade Tran
 * Lab #14    : Linked Lists
 * CLASS      : CS 1C
 * SECTION    : TTh: 12:30 - 2:50
*************************************************************************/
  
#include <iostream>
#include "doublyLinkedList.h"  
using namespace std;  

int main()
{
	int array[] = {88,78,62,143,60};
	doublyLinkedList<int> list1;
	int i = 0;
	
	// Inserting numbers to linked list
	for(int i = 0; i < 5; i++)
		list1.insert(array[i]);

	cout << "= Linked list 1:" << endl;
	list1.print();
	cout << endl;

	doublyLinkedList<int> copied_list(list1);

	// Using copy constructor
	cout << "= Linked list 1 copy constructor:" << endl;
	copied_list.print();
	cout << endl;

	// Using copy assignment
	copied_list = list1;
	cout << "= Linked list 1 copy assignment:" << endl;
	cout << endl;

	doublyLinkedList<int> move_to_list(list1);

	// Using move constructor
	cout << "= Linked list 1 move constructor:" << endl;
	move_to_list.print();
	cout << endl;

	// Using move assignment
	move_to_list = list1;
	cout << "= Linked list 1 move assignment:" << endl;
	cout << endl;



	return 0;
}
