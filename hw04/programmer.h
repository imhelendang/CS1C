#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_

#include "employee.h"
#include "date.h"
using namespace std;

/* class type programmer - derived class from class type employee. */
class programmer: public employee {
private:
    std::string d_number;     /* Department number.                                                 */
    std::string sup_name;     /* Supervisor’s name.                                                 */
    int inc_salary;           /* Percent of salary increase.                                        */
    bool c_id;                /* A C++ identifier - true mean is a C++ identifier, false otherwise. */
    bool java_id;             /* A Java identifier - true mean is a C++ identifier, false otherwise.*/

public:
    /* Default constructor. 
     * Pre-condition: <none>
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
    programmer();

    /* Constructor with parameters.
     * Pre-condition: string, int, and bool variables.
     * Post-condition: the created object is in valid state, mean all data elements are initialized according to the parameters.
     */
    programmer(std::string temp_name, std::string temp_ID, int temp_day, int temp_month, int temp_year, std::string temp_job, std::string temp_salary, std::string temp_phone,
              char temp_gender, int temp_age, std::string temp_dNum, std::string temp_supName, int temp_incSalary, bool temp_cID, bool temp_javaID);

    /* Destructor.
     * Pre-condition: <none>
     * Psot-condition: objects are deleted.
     */
    ~programmer() {}

    /* Setters.
     * Pre-condition: string, string, int, bool, bool
     * Post-condition: data members: d_number, sup_name, inc_salary, c_id, and java_id are initialized according to the parameters.
     */
    void set_dnum(std::string);
    void set_supname(std::string);
    void set_incsalary(int);
    void set_cid(bool);
    void set_javaid(bool);

    /* Getters.
     * Pre-condition: the functions can't change the data members value.
     * Post-condition: return data members values.
     */
    std::string get_dnum() const;
    std::string get_supname() const;
    int get_incsalary() const;
    bool get_cid() const;
    bool get_javaid() const;

    /* Overloading the operators.
     * Pre-condition: istream, ostream, class object (passed by reference).
     * Post-condition: 
     * + For ">>": read in data and initialize the object's private data.
     * + For "<<": similar to print function but only can be used by programmer type object.
     */	
    friend istream & operator>>(istream& is, programmer& other);
    friend ostream & operator<<(ostream& os, const programmer& other);
};

#endif /* PROGRAMMER_H_ */
