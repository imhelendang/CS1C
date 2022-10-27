#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>      /* To read and write to a file. */
#include "date.h"
using namespace std;

/* Global variable represents the dollar sign. */
const char DOL = '$';

/* Base class type employee. */
class employee {
private:
	std::string name;
	std::string ID;
	date hire_date;          /* Composed data element. */
	std::string job_titile;    
    std::string salary;
    std::string phone;
	char gender;
    int age;

public:

    /* Default constructor. 
     * Pre-condition: <none>
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
	employee();		

    /* Constructor with parameters.
     * Pre-condition: string and int variables.
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
	employee(std::string temp_name, std::string temp_ID, int temp_day, int temp_month, int temp_year, std::string temp_job, std::string temp_salary, std::string temp_phone,
              char temp_gender, int temp_age);		

    /* Destructor.
     * Pre-condition: <none>
     * Psot-condition: objects are deleted.
     */
	virtual ~employee() {}; 		

    /* Setters.
     * Pre-condition: string, int, char.
     * Post-condition: name, ID, hire_date, job_title, salary, phone, gender, and age must be assigned to a valid variable.
     */
	void set_name(std::string);
	void set_ID(std::string);
	void set_hiredate(int, int, int);
	void set_job(std::string);
    void set_salary(std::string);
    void set_phone(std::string);
	void set_gender(char);
    void set_age(int);


    /* Getters.
     * Pre-condition: <none>
     * Post-condition: return all the object's private data accoridng to the function.
     */	
    std::string get_name() const;
	std::string get_ID() const;
	std::string get_hiredate() const;
	std::string get_job() const;
    std::string get_salary() const;
    std::string get_phone() const;
	char get_gender() const;
    int get_age() const;

    
    /* Function to update the employee age.
     * Pre-condition: class object and an int (passed by reference).
     * Post-condition: print out the employee's age that's just updated.
     */	
    friend void update_age(employee& other, int& add);


    /* Print function.
     * Pre-condition: the function can't change the data members value.
     * Post-condition: print out the information in a certain format.
     */		
    void print_employee(ostream& os) const;


    /* Friend function used to compare phone a employee's phone number with a programmer phone's number.
     * Followed by change_phone function to update new phone number for the employee.
     * Pre-condition: employee type object and string.
     * Post-condition: compare the "phone" data member. 
     *                 If they are identical, change the employee object's "phone" by calling "change_phone()".
     */	
    friend void compare_phone(employee& other1,  const string&);
    friend void change_phone(employee& other1);


    /* Overloading the operators.
     * Pre-condition: istream, ostream, class object (passed by reference).
     * Post-condition: 
     * + For "==": return true if 2 employees have the same phone numbers.
     * + For "+":  update an employee's age.
     * + For ">>": read in data and initialize the object's private data.
     * + For "<<": similar to print function but only can be used by employee type object.
     */	
    bool operator==(const employee& other);	
    employee operator+(int& add);
    friend istream & operator>>(istream& is, employee& other);
    friend ostream & operator<<(ostream& os, const employee& other);

    
};

#endif /* EMPLOYEE_H_ */
