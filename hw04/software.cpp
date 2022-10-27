#include "employee.h"
#include "software.h"

/* **************************************************************************************** */
/*                                       Constructors.                                      */
/* **************************************************************************************** */

software::software() {
    d_number = "N/A";
    sup_name = "N/A";
    inc_salary = 0;
    years = 0;
}

software::software(std::string temp_name, std::string temp_ID, int temp_day, int temp_month, int temp_year, std::string temp_job, std::string temp_salary, std::string temp_phone,
              char temp_gender, int temp_age, std::string temp_dNum, std::string temp_supName, int temp_incSalary, int temp_years) 
        : employee(temp_name, temp_ID, temp_day, temp_month, temp_year, temp_job, temp_salary, temp_phone, temp_gender, temp_age) {
    set_dnum(temp_dNum);
    set_supname(temp_supName);
    set_incsalary(temp_incSalary);
    set_years(temp_years);
}

/* **************************************************************************************** */
/*                                          Setters.                                        */
/* **************************************************************************************** */
void software::set_dnum(string other) {
    d_number = other;
}

void software::set_supname(string other) {
    sup_name = other;
}

void software::set_incsalary(int other) {
    inc_salary = other;
}

void software::set_years(int other) {
    years = other;
}

/* **************************************************************************************** */
/*                                          Getters.                                        */
/* **************************************************************************************** */
string software::get_dnum() const {
    return d_number;
}

string software::get_supname() const {
    return sup_name;
}   

int software::get_incsalary() const {
    return inc_salary;
}

int software::get_years() const {
    return years;
}   

/* **************************************************************************************** */
/*                                          Print.                                          */
/* **************************************************************************************** */
istream & operator>>(istream& is, software& other) {
    string temp_name, temp_ID, temp_job, temp_salary, temp_phone, temp_dNum, temp_supName;
    int temp_day, temp_month, temp_year, temp_age, temp_incSalary, temp_years; 
    char temp_gender;

    getline(is, temp_name);
    getline(is, temp_ID);
    is >> temp_day;
    is.ignore(1000, '\n');
    is >> temp_month;
    is.ignore(1000, '\n');
    is >> temp_year;
    is.ignore(1000, '\n');
    getline(is, temp_job);
    getline(is, temp_salary);
    getline(is, temp_phone);
    is >> temp_gender;
    is.ignore(1000, '\n');
    is >> temp_age;
    is.ignore(1000, '\n'); 
    getline(is, temp_dNum);
    getline(is, temp_supName);
    is >> temp_incSalary;
    is.ignore(1000, '\n');
    is >> temp_years;
    is.ignore(1000, '\n'); 

    /* Assign information for "programmer" object. */
    other.set_name(temp_name);
    other.set_ID(temp_ID);
    other.set_hiredate(temp_day, temp_month, temp_year);
    other.set_job(temp_job);
    other.set_salary(temp_salary);
    other.set_phone(temp_phone);
    other.set_gender(temp_gender);
    other.set_age(temp_age);
    other.set_dnum(temp_dNum);
    other.set_supname(temp_supName);
    other.set_incsalary(temp_incSalary);
    other.set_years(temp_years);
    
    return is;
}

ostream & operator<<(ostream& os, const software& other) {

    /* Print out all data members. */
    os << left << setw(19) << "\n= " + other.get_name() << setw(16) << other.get_dnum() << setw(21) << other.get_supname() 
         << setw(11) << other.get_incsalary() << setw(2) << other.get_years() << "                                   ="; 

    return os;
}