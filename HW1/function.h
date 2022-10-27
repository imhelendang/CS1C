#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>      /* To read and write to a file. */
#include <vector>
using namespace std;

typedef enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, Unknown} Day;

static const string enum_str[] = {  "Monday: 01/17/2022", "Tuesday: 01/18/2022", 
                                    "Wednesday: 01/19/2022", "Thursday: 01/20/2022",
                                    "Friday: 01/21/2022", "Saturday: 01/22/2022", "Sunday: 01/23/2022" };

void part_a();

void part_b();
void read_from_afile(int list[]);
void sort_array(int list[]);
void print_number(ofstream &outfile, int list[]);

void part_c();

#endif /* FUNCTION_H_ */