#include "date.h"

date::date() {
    day = 0;
    month = 0;
    year = 0;
}

date::date(int temp_day, int temp_month, int temp_year) {
    day = temp_day;
    month = temp_month;
    year = temp_year;
}

void date::set_day(int temp_day) {
    day = temp_day;
}

void date::set_month(int temp_month) {
    month = temp_month;
}

void date::set_year(int temp_year) {
    year = temp_year;
}

int date::get_day() const {
    return day;
}

int date::get_month() const {
    return month;
}

int date::get_year() const {
    return year;
}
