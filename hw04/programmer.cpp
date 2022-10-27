#include "programmer.h"
#include "employee.h"
#include "date.h"

/* **************************************************************************************** */
/*                                       Constructors.                                      */
/* **************************************************************************************** */
programmer::programmer() {
    d_number = "N/A";
    sup_name = "N/A";
    inc_salary = 0;
    c_id = false;
    java_id = false;
}

programmer::programmer(string temp_name, string temp_ID, int temp_day, int temp_month, int temp_year, string temp_job, string temp_salary, string temp_phone,
              char temp_gender, int temp_age, string temp_dNum, string temp_supName, int temp_incSalary, bool temp_cID, bool temp_javaID)
        : employee(temp_name, temp_ID, temp_day, temp_month, temp_year, temp_job, temp_salary, temp_phone, temp_gender, temp_age) {
    set_dnum(temp_dNum);
    set_supname(temp_supName);
    set_incsalary(temp_incSalary);
    set_cid(temp_cID);
    set_javaid(temp_javaID);
}

/* **************************************************************************************** */
/*                                          Setters.                                        */
/* **************************************************************************************** */
void programmer::set_dnum(string temp_dNum) {
    d_number = temp_dNum;
}

void programmer::set_supname(string temp_supName) {
    sup_name = temp_supName;
}

void programmer::set_incsalary(int temp_incSalary) {
    inc_salary = temp_incSalary;
}

void programmer::set_cid(bool temp_cID) {
    c_id = temp_cID;
}

void programmer::set_javaid(bool temp_javaID) {
    java_id = temp_javaID;
}

/* **************************************************************************************** */
/*                                          Getters.                                        */
/* **************************************************************************************** */
string programmer::get_dnum() const {
    return d_number;
}

string programmer::get_supname() const {
    return sup_name;
}

int programmer::get_incsalary() const {
    return inc_salary;
}

bool programmer::get_cid() const {
    return c_id;
}

bool programmer::get_javaid() const {
    return java_id;
}

/* **************************************************************************************** */
/*                                          Print.                                          */
/* **************************************************************************************** */
istream & operator>>(istream& is, programmer& other) {
    string temp_name, temp_ID, temp_job, temp_salary, temp_phone, temp_dNum, temp_supName;
    int temp_day, temp_month, temp_year, temp_age, temp_incSalary, temp_cID, temp_javaID; 
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
    is >> temp_cID;
    is.ignore(1000, '\n');
    if(temp_cID == 1) other.set_cid(true); else other.set_cid(false);
    is >> temp_javaID;
    is.ignore(1000, '\n');
    if(temp_javaID == 1) other.set_javaid(true); else other.set_javaid(false);

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

    return is;
}

ostream & operator<<(ostream& os, const programmer& other) {
    
    /* Print out all data members. */
    os << left << setw(19) << "\n= " + other.get_name() << setw(16) << other.get_dnum() << setw(21) << other.get_supname() 
         << setw(11) << other.get_incsalary();
    if(other.get_cid() == true) 
        os << setw(15) << "YES";
    else
        os << setw(15) << "NO";
        
    if(other.get_javaid() == true)
        os << setw(22) << "YES" << "=";
    else
        os << setw(22) << "NO" << "=";

    return os;
}
