#ifndef SOFTWARE_H_
#define SOFTWARE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "employee.h"
#include "programmer.h"
#include "date.h"
using namespace std;

/* class type software - derived class from class type employee. */
class software: public employee {
private:
    string d_number;     /* Department number.          */
    string sup_name;     /* Supervisor’s name.          */
    int inc_salary;      /* Percent of salary increase. */
    int years;           /* Years of experience.        */

public:
    /* Default constructor. 
     * Pre-condition: <none> 
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
    software();

    /* Constructor with parameters.
     * Pre-condition: string, int, and char variables.
     * Post-condition: the created object is in valid state, mean all data elements are initialized according to the parameters.
     */
    software(std::string temp_name, std::string temp_ID, int temp_day, int temp_month, int temp_year, std::string temp_job, std::string temp_salary, std::string temp_phone,
              char temp_gender, int temp_age, std::string temp_dNum, std::string temp_supName, int temp_incSalary, int temp_years);

    /* Destructor.
     * Pre-condition: <none>
     * Psot-condition: objects are deleted.
     */
    ~software() {}


    /* Setters.
     * Pre-condition: string, string, int, bool, bool
     * Post-condition: data members: d_number, sup_name, inc_salary, and years are initialized according to the parameters.
     */
    void set_dnum(string);
    void set_supname(string);
    void set_incsalary(int);
    void set_years(int);

    /* Getters.
     * Pre-condition: the functions can't change the data members value.
     * Post-condition: return data members values.
     */
    string get_dnum() const;
    string get_supname() const;
    int get_incsalary() const;
    int get_years() const;

    /* Overloading the operators.
     * Pre-condition: istream, ostream, class object (passed by reference).
     * Post-condition: 
     * + For ">>": read in data and initialize the object's private data.
     * + For "<<": similar to print function but only can be used by programmer type object.
     */	
    friend istream & operator>>(istream& is, software& other);
    friend ostream & operator<<(ostream& os, const software& other);
};



#endif /* SOFTWARE_H_ */