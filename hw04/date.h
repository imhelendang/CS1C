#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* class type date. */
class date {
private:
    int day;
    int month;
    int year;

public:
    /* Default constructor. 
     * Pre-condition: <none>
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
	date();	

    /* Constructor with parameters.
     * Pre-condition: int, int, int
     * Post-condition: the created object is in valid state, mean all data elements are initialized.
     */
	date(int, int ,int);	

    /* Destructor.
     * Pre-condition: <none>
     * Post-condition: objects are deleted.
     */
	~date() {}; 

    /* Setters.
     * Pre-condition: int, int, int
     * Post-condition: data members: day, month, and year are initialized according to the parameters.
     */
	void set_day(int);
	void set_month(int);
	void set_year(int);

    /* Getters.
     * Pre-condition: the functions can't change the data members value.
     * Post-condition: return data elements: day, month, and year.
     */	
    int get_day() const;
	int get_month() const;
	int get_year() const;

};


#endif /* DATE_H_ */
