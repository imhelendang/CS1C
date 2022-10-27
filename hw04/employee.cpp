#include "employee.h"

/* **************************************************************************************** */
/*                                       Constructors.                                      */
/* **************************************************************************************** */
employee::employee() {
    name = "N/A";
    ID = "N/A";
    job_titile = "N/A";
    salary = "N/A";
    phone = "N/A";
    gender = 'X';
    age = 0;
}

employee::employee(string temp_name, string temp_ID, int temp_day, int temp_month, int temp_year, string temp_job, string temp_salary, string temp_phone,
              char temp_gender, int temp_age) {
    set_name(temp_name);
    set_ID(temp_ID);
    set_hiredate(temp_day, temp_month, temp_year);
    set_job(temp_job);
    set_salary(temp_salary);
    set_phone(temp_phone);
    set_gender(temp_gender);
    set_age(temp_age);
}

/* **************************************************************************************** */
/*                                          Setters.                                        */
/* **************************************************************************************** */
void employee::set_name(string temp_name) {
    name = temp_name;
}

void employee::set_ID(string temp_ID) {
    ID = temp_ID;
}

void employee::set_hiredate(int temp_day, int temp_month, int temp_year) {
    hire_date.set_day(temp_day);
    hire_date.set_month(temp_month);
    hire_date.set_year(temp_year);
}  

void employee::set_job(string temp_job) {
    job_titile = temp_job;
}

void employee::set_salary(string temp_salary) {
    salary = temp_salary;
}

void employee::set_phone(string temp_phone) {
    phone = temp_phone;
}

void employee::set_gender(char temp_gender) {
    gender = temp_gender;
}

void employee::set_age(int temp_age) {
    age = temp_age;
}

/* **************************************************************************************** */
/*                                          Getters.                                        */
/* **************************************************************************************** */
string employee::get_name() const {
    return name;
}

string employee::get_ID() const {
    return ID;
}

string employee::get_hiredate() const {
    string a, b, c;

    if(hire_date.get_day() < 10)
        a = "0" + to_string(hire_date.get_day());
    else 
        a = to_string(hire_date.get_day());

    if(hire_date.get_month() < 10)
        b = "0" + to_string(hire_date.get_month());
    else 
        b = to_string(hire_date.get_month());

    if(hire_date.get_year() == 0) {
        c = "0000";
    }
    else
        c = to_string(hire_date.get_year());

    return a + "/" + b + "/" + c;
}

string employee::get_job() const {
    return job_titile;
}

string employee::get_salary() const {
    return salary;
}

string employee::get_phone() const {
    return phone;
}

char employee::get_gender() const {
    return gender;
}

int employee::get_age() const {
    return age;
}

/* **************************************************************************************** */
/*                                          Print.                                          */
/* **************************************************************************************** */
void employee::print_employee(ostream& os) const {

    /* Print out all data members. */
    os << left << setw(19) << "\n= " + get_name() << setw(16) << get_ID() << setw(15) << get_phone() 
         << setw(6) << get_age() << setw(9) << get_gender() << setw(15) << get_job() << DOL << " " << setw(8) << get_salary()
         << "   " << get_hiredate() + " =";
}

void update_age(employee& other, int& add) {

    /* Updating the employee age and print out the constant. */
    other = other + add;

    cout << "= " << other.get_name() << "'s age has been updated.";
    if(other.get_gender() == 'M') 
        cout << " He";
    else
        cout << " She";

    cout << " is now " << add << " years older!\n";
}


/* **************************************************************************************** */
/*                                    Extra functions.                                      */
/* **************************************************************************************** */
void compare_phone(employee& other1,  const string& other2) {
    
    if(other1.get_phone() == other2) {
        cout << "= " << other1.get_name() << " has the same phone number as one of the programmers that is: " << other1.get_phone() <<"\n";
        cout << "= Changing the employee's phone number. Please enter new phone number for " << other1.get_name() << endl;
        change_phone(other1);
        cout << "= Successfully update phone number!\n\n";
    }
}

void change_phone(employee& other1) {

    string temp;
    getline(cin, other1.phone);
}

/* **************************************************************************************** */
/*                                Overloading Operators.                                    */
/* **************************************************************************************** */ 
bool employee::operator==(const employee& other) {

    if(get_phone() == other.get_phone()) {
        return true;
    }

    return false;
}

istream & operator>>(istream& is, employee& other) {

    int temp_day, temp_month, temp_year;

    getline(is, other.name);
    getline(is, other.ID);
    is >> temp_day;
    is.ignore(1000, '\n');
    is >> temp_month;
    is.ignore(1000, '\n');
    is >> temp_year;
    is.ignore(1000, '\n');
    other.set_hiredate(temp_day, temp_month, temp_year);
    getline(is, other.job_titile);
    getline(is, other.salary);
    getline(is, other.phone);
    is >> other.gender;
    is.ignore(1000, '\n');
    is >> other.age;
    is.ignore(1000, '\n');

    return is;
}

ostream & operator<<(ostream& os, const employee& other) {

    /* Print out all data members. */
    os << left << setw(19) << "\n= " + other.get_name() << setw(16) << other.get_ID() << setw(15) << other.get_phone() 
         << setw(6) << other.get_age() << setw(9) << other.get_gender() << setw(15) << other.get_job() << DOL << " " << setw(8) << other.get_salary()
         << "   " << other.get_hiredate() + " =";

    return os;
}

employee employee::operator+(int& add) {
    
    age = age + add;
    return *this;
}
