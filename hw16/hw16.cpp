// hw16.cpp
// to illustrate stl algorithms & function objects

/*************************************************************************
 * AUTHOR     : Jade Tran
 * hw16       : stl algorithms & function objects
 * CLASS      : CS 1C
 * SECTION    : TTh: 12:30-2:50
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

using std::exception;
using std::length_error;
using std::vector;
using std::list;

// function & class definitions go into hw16.cpp:

// hw16.cpp

namespace hw16 {

//
// algorithm, function object example code adapted from Chapter 21
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--Q#1-------------------------------------------------------------------------

template<typename InputIterator, typename EqualityComparable>
InputIterator find(InputIterator first,InputIterator last, const EqualityComparable& val) 
    // find the first element in [first,last) that equals value
{
    for (InputIterator p = first; p!=last; ++p)
        if (*p==val) return p;
    return last;
}

template<typename InputIterator, typename EqualityComparable>
InputIterator find_improved(InputIterator first,InputIterator last, const EqualityComparable& val) 
    // find the first element in [first,last) that equals value
{
    InputIterator p = first;
    while (p!=last && !(*first==val)) {
        ++p;
    }
    return p;
}

//--Q#2-------------------------------------------------------------------------

template<typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred)
    // find the first element in [first,last) that satisfies predicate
{
    InputIterator p = first;
    while (p!=last && !pred(*first)) {
        ++p;
    }
    return p;
}

//--Q#2-------------------------------------------------------------------------

bool even(int x) { return ((x%2)==0); } // test for even ints via modulo

//------------------------------------------------------------------------------

bool less_than_31(int x) { 
    return (x < 31);
}

//------------------------------------------------------------------------------

int global_value; // the value to which less_than_v() compares its argument
bool less_than_v(int x) { 
    return (x < global_value);
}

//--Q#3-------------------------------------------------------------------------

// Less_than function object class definition goes here
class Less_than {
    int v;
    public:
    Less_than(int v) : v{v} { }      // storing value
    bool operator()(int x) const { return x < v; }
};

//--Q#4-------------------------------------------------------------------------

struct Shape
{
    Shape(int id) : id{id} { }
    virtual ~Shape() { }
    virtual int calc_perimeter() const = 0;
    virtual int calc_area() const { return -1; }
    int id; // shape id
};

std::ostream& operator<<(std::ostream& os, const Shape& s)
{
    return os << s.id;
}

//------------------------------------------------------------------------------

struct Line : public Shape
{
    Line(int id, int p, int a) : Shape{id}, perimeter{p}, area{a} { }
    int calc_perimeter() const override { return perimeter; }
    int calc_area() const override { return area; }
    int perimeter; // shape type perimeter
    int area;      // shape type area
};

//------------------------------------------------------------------------------

struct Square : public Shape
{
    Square(int id, int p, int a) : Shape{id}, perimeter{p}, area{a} { }
    int calc_perimeter() const override { return perimeter; }
    int calc_area() const override { return area; }
    int perimeter; // shape type perimeter
    int area;      // shape type area
};

//--Q#4-------------------------------------------------------------------------

// comparisons for Shape* objects:

struct Cmp_by_id {
    bool operator()(const Shape* s1, const Shape* s2) const
    { 
        if(s1->id < s2->id)
            return true;

        return false; 
    } // dereference pointer, compare ids
};

//------------------------------------------------------------------------------

// Cmp_by_perimeter function object struct definition goes here
struct Cmp_by_perimeter {
    bool operator()(const Shape* s1, const Shape* s2) const
    { 
        if(s1->calc_perimeter() < s2->calc_perimeter())
            return true;

        return false; 
    } // dereference pointer, compare ids
};

//------------------------------------------------------------------------------

// Cmp_by_area function object struct definition goes here
struct Cmp_by_area {
    bool operator()(const Shape* s1, const Shape* s2) const
    { 
        if(s1->calc_area() < s2->calc_area())
            return true;

        return false; 
    } // dereference pointer, compare ids
};

//--Q#5-------------------------------------------------------------------------

template<typename In, typename Out>
    // requires Input_iterator<In> and Output_iterator<Out>
Out copy(In first, In last, Out result)
    // copy elements from [first,last) to result
{
    while (first!=last) {
        *result = *first; // copy element
        ++result;
        ++first;
    }
    return result;
}

//------------------------------------------------------------------------------

template<typename In, typename Out, typename Pred>
    // requires Input_iterator<In> and Output_iterator<Out> and
    //          Predicate<Pred, Value_type<In>>
Out copy_if(In first, In last, Out result, Pred pred)
    // copy elements from [first,last) to result that sastisfy predicate
{
   while (first!=last) {
       if(pred(*first))
            *result++ = *first;

        ++first;
    }
    return result; // included so that incomplete lab code will compile
}

//--Q#5-------------------------------------------------------------------------

template<typename Val>
    // requires LessThan_comparable<Val>
class Range_low_to_high {
    Val v_low;
    Val v_high;
public:
    Range_low_to_high(Val low, Val high) : v_low{low}, v_high{high} { }
    bool operator()(Val x) const { return !(x < v_low) && !(v_high > x); }
};

//------------------------------------------------------------------------------

} // hw16

//------------------------------------------------------------------------------

using namespace hw16;

//
// algorithm, function object example code adapted from Chapter 21
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*            Running hw16            * " << endl;
	cout << "*      Programmed by Jade Tran       * " << endl;
	cout << "*      CS1C TTh & 12:30 - 2:50       * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

    // NOTE: uncomment code below once algorithm definitions Q#1-5 are complete

	// Q#1 - find algorithm

    vector<int> v = {40,5,4,3,2,-99,100,10,500,5}; // init stl vector of ints using initializer list

    // print vector v
    cout << "vector v: ";
    for (const auto& x : v) cout << x << " "; // use auto type deduction (x is an int),
    cout << endl << endl;                     // range-for-loop to print v

    int x = 5;
    vector<int>::iterator p = hw16::find(v.begin(),v.end(),x); // find value of 5 in v
    if (p!=v.end())
        cout << "find alg: found value of in vector v " << *p << endl << endl;
    else
        cout << "find alg: can't find value in vector v" << endl << endl;

	// Q#2 - find_if algorithm with predicates
                                                    // find first even int in v
    auto q = hw16::find_if(v.begin(),v.end(),even); // use auto-type deduction for output iterator q
    if (q!=v.end())                                 // (q is a vector<int>::iterator)
        cout << "find_if alg: found even value of in vector v " << *q << endl;
    else
        cout << "find_if alg: can't find even value in vector v" << endl;

    p = hw16::find_if(v.begin(),v.end(),less_than_31); // find first int in v less than 31
    if (p!=v.end())
        cout << "find_if alg: found less_than_31 value of in vector v " << *p << endl;
    else
        cout << "find_if alg: can't find less_than_31 value in vector v" << endl;

    global_value = -100;
    p = hw16::find_if(v.begin(),v.end(),less_than_v); // find first int in v less than -100
    if (p!=v.end())
        cout << "find_if alg: found less_than_v value of in vector v " << *p << endl << endl;
    else
        cout << "find_if alg: can't find less_than_v value in vector v" << endl << endl;

	// Q#3 - find_if algorithm with function objects

    p = hw16::find_if(v.begin(),v.end(),Less_than(4)); // find first int in v less than 4
    if (p!=v.end())
        cout << "find_if alg: found Less_than(4) value of in vector v " << *p << endl << endl;
    else
        cout << "find_if alg: can't find Less_than(4) value in vector v" << endl << endl;

	// Q#4 - sort algorithm + Shape class, function objects

    vector<Shape*> vs;
    vs.push_back(new Line{10,5,-1});       // store pointer to line1 in vs
    vs.push_back(new Line{5,10,-1});       // store pointer to line2 in vs
    vs.push_back(new Line{1,15,-1});       // store pointer to line3 in vs
    vs.push_back(new Square{100,400,625}); // store pointer to square1 in vs
    vs.push_back(new Square{101,40,100});  // store pointer to square2 in vs
    vs.push_back(new Square{102,60,225});  // store pointer to square3 in vs

    std::sort(vs.begin(),vs.end(),Cmp_by_id()); // sort shapes by id (using std sort algorithm)
    cout << "shapes sorted by id: ";
    for (const auto x : vs) cout << *x << " "; // use auto type deduction (x is a Shape*),
    cout << endl << endl;                      // range-for-loop to print vs

    std::sort(vs.begin(),vs.end(),Cmp_by_perimeter()); // sort shapes by perimeter
    cout << "shapes sorted by perimeter: " << endl;
    for (const auto x : vs)
    {
        cout << "id " << *x;
        cout << ", perimeter " << x->calc_perimeter() << endl;
    }
    cout << endl;

    std::sort(vs.begin(),vs.end(),Cmp_by_area()); // sort shapes by area
    cout << "shapes sorted by area: " << endl;
    for (const auto x : vs)
    {
        cout << "id " << *x;
        cout << ", area " << x->calc_area() << endl;
    }
    cout << endl;

    // free all shapes
    for (Shape* pS : vs) delete pS; // delete all shape objects, otherwise memory will leak

	// Q#5 - copy_if algorithm with function objects

    try
    {
        list<int> l(v.size()); // create a stl list with size = v size

        if (l.size() < v.size()) throw length_error("target container too small"); // throw exceptoin when
        // copy elements from vector v to list l within range 5 <= elem <= 50      // target container too small
        hw16::copy_if(v.begin(), v.end(), l.begin(), Range_low_to_high<int>(5,50));
        
        // print list l
        cout << "list l: ";
        for (const auto& x : l) cout << x << " ";
        cout << endl << endl;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << endl; 
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!" << endl; 
        return 2;
    }


    return 0;
}

//--------------------------------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#1 - What kinds of operations must type InputIterator and type EqualityComparible support (i.e. 
// what are the type requirements) such that find is able to work? 
// Ans: 
// For InputIterator type, it needs to support postincrement, preincrement, postincrement and derefernece operations.
// For EqualityComparible type, it needs to support equality and inequality operations.

// Q#5 -  Explain what this means in terms of operations copy_if type parameters must support. What 
// operations must these types have such that copy_if will work? 
// copy_if copies elements from a valid range Inputiterator<In> [frist, last) to the range
// Outputiterator<Out> result which needs to be not an iterator within the range [first, last). Linearly, 
// this function performs exactly last - first applications of pred and exactly last - first assignments.
// Then, it stores the results in result.
// In order to work properly, copy_if needs to have postincrement, preincrement, postincrement and derefernece operations
