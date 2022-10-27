#include "queue.h"

const int STD_SIZE = 6;

/* main() program */
int main() {

	cout << fixed << showpoint << right << setprecision(2); //set up number format

	cout << "\n= WORK WITH OBJECT TYPE OF INTEGER!\n\n";
    // create a queue of capacity 4
    queue<int> int_object(STD_SIZE);
	queue<int> int_moved_object;
	int number_elements = STD_SIZE, times_pop = STD_SIZE-2;
	int input;
	char discard;

	cout << "= Add 6 elements to the queue!\n";
	while (number_elements > 0) {
		int_object.enqueue(number_elements);
		number_elements--;
	}

	// using move constructor to print out the object
	int_moved_object = int_object;

	cout << "= The complete object: \n";
	while(!int_moved_object.isEmpty()){
		cout << int_moved_object.front() << ' ';
		int_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 4 elements from the queue!\n";
	
	while(times_pop > 0) {
		cout << int_object.front() << ' ';
		int_object.dequeue();
		times_pop--;
	}

	cout << "\n= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Now add 5 elements to the queue!\n";
	int_object.enqueue(12);
	int_object.enqueue(15);
	int_object.enqueue(20);
	int_object.enqueue(100);
	cout << "= The queue now is full. Trying to add another element to the queue using try catch method to catch error.\n";
	try{
		int_object.enqueue(203);	// Can't add since the queue is full
	} catch (std::exception& ex) {
		cout << ex.what() << endl;
	}
	

	// using move constructor to print out the object
	int_moved_object = int_object;

	cout << "= The complete object: \n";
	while(!int_moved_object.isEmpty()){
		cout << int_moved_object.front() << ' ';
		int_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 3 elements from the queue!\n";
	times_pop = STD_SIZE - 3;
	if(int_object.isEmpty()) {
		cout << "= The queue currently is empty. Cannot remove from an empty queue!";
	}
	else {
		while(times_pop > 0) {
			cout << int_object.front() << ' ';
			int_object.dequeue();
			times_pop--;
		}
	}
	cout << endl;

	cout << "\n= Deleting the whole queue before exiting!" << endl;
	times_pop = int_object.size();
	while(times_pop > 0) {
		cout << int_object.front() << ' ';
		int_object.dequeue();
		times_pop--;
	}
	cout << endl;

	cout << "= Try to delete from an empty queue using try catch method!" << endl;
	try {
		int_object.dequeue();
	} catch (std::exception& ex1) {
		cout << ex1.what() << endl;
	}

	cout << "\n= WORK WITH OBJECT TYPE OF DOUBLE!\n\n";

	queue<double> double_object(STD_SIZE);
	queue<double> double_moved_object;
	number_elements = STD_SIZE;
	times_pop = STD_SIZE-2;

	cout << "= Add 6 elements to the queue!\n";
	while (number_elements > 0) {
		double_object.enqueue(number_elements);
		number_elements--;
	}

	// using move constructor to print out the object
	double_moved_object = double_object;

	cout << "= The complete object: \n";
	while(!double_moved_object.isEmpty()){
		cout << double_moved_object.front() << ' ';
		double_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 4 elements from the queue!\n";
	
	while(times_pop > 0) {
		cout << double_object.front() << ' ';
		double_object.dequeue();
		times_pop--;
	}

	cout << "\n= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Now add 5 elements to the queue!\n";
	double_object.enqueue(12.35);
	double_object.enqueue(15.62);
	double_object.enqueue(20.19);
	double_object.enqueue(100.04);
	cout << "= The queue now is full. Trying to add another element to the queue using try catch method to catch error.\n";
	try{
		double_object.enqueue(203.0);	// Can't add since the queue is full
	} catch (std::exception& ex) {
		cout << ex.what() << endl;
	}
	

	// using move constructor to print out the object
	double_moved_object = double_object;

	cout << "= The complete object: \n";
	while(!double_moved_object.isEmpty()){
		cout << double_moved_object.front() << ' ';
		double_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 3 elements from the queue!\n";
	times_pop = STD_SIZE - 3;
	if(double_object.isEmpty()) {
		cout << "= The queue currently is empty. Cannot remove from an empty queue!";
	}
	else {
		while(times_pop > 0) {
			cout << double_object.front() << ' ';
			double_object.dequeue();
			times_pop--;
		}
	}
	cout << endl;

	cout << "\n= Deleting the whole queue before exiting!" << endl;
	times_pop = double_object.size();
	while(times_pop > 0) {
		cout << double_object.front() << ' ';
		double_object.dequeue();
		times_pop--;
	}
	cout << endl;

	cout << "= Try to delete from an empty queue using try catch method!" << endl;
	try {
		double_object.dequeue();
	} catch (std::exception& ex1) {
		cout << ex1.what() << endl;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "\n= WORK WITH OBJECT TYPE OF STRING!\n\n";

	queue<string> string_object(STD_SIZE);
	queue<string> string_moved_object;
	number_elements = STD_SIZE;
	times_pop = STD_SIZE-2;

	cout << "= Add 6 elements to the queue!\n";
	string_object.enqueue("a");
	string_object.enqueue("b");
	string_object.enqueue("c");
	string_object.enqueue("d");
	string_object.enqueue("e");
	string_object.enqueue("f");

	// using move constructor to print out the object
	string_moved_object = string_object;

	cout << "= The complete object: \n";
	while(!string_moved_object.isEmpty()){
		cout << string_moved_object.front() << ' ';
		string_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 4 elements from the queue!\n";
	if(string_object.isEmpty()) {
		cout << "= The queue currently is empty. Cannot remove from an empty queue!";
	}
	else {
		while(times_pop > 0) {
			cout << string_object.front() << ' ';
			string_object.dequeue();
			times_pop--;
		}
	}

	cout << "\n= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Now add 5 elements to the queue!\n";
	string_object.enqueue("q");
	string_object.enqueue("w");
	string_object.enqueue("r");
	string_object.enqueue("y");
	cout << "= The queue now is full. Trying to add another element to the queue using try catch method to catch error.\n";
	try{
		string_object.enqueue("o");	// Can't add since the queue is full
	} catch (std::exception& ex) {
		cout << ex.what() << endl;
	}
	

	// using move constructor to print out the object
	string_moved_object = string_object;

	cout << "= The complete object: \n";
	while(!string_moved_object.isEmpty()){
		cout << string_moved_object.front() << ' ';
		string_moved_object.dequeue();
	}
	cout << endl;

	cout << "= Press any key to continue..";
	cin >> discard;
	cin.ignore(1000, '\n');
	cout << endl;

	cout << "= Then delete 3 elements from the queue!\n";
	times_pop = STD_SIZE - 3;
	if(string_object.isEmpty()) {
		cout << "= The queue currently is empty. Cannot remove from an empty queue!";
	}
	else {
		while(times_pop > 0) {
			cout << string_object.front() << ' ';
			string_object.dequeue();
			times_pop--;
		}
	}
	cout << endl;

	cout << "\n= Deleting the whole queue before exiting!" << endl;
	times_pop = string_object.size();
	while(times_pop > 0) {
		cout << string_object.front() << ' ';
		string_object.dequeue();
		times_pop--;
	}
	cout << endl;

	cout << "= Try to delete from an empty queue using try catch method!" << endl;
	try {
		string_object.dequeue();
	} catch (std::exception& ex1) {
		cout << ex1.what() << endl;
	}
	

	cout << "= Temrinating the program!\n";
    return 0;
}
