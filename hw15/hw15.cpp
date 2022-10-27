// hw15.cpp
// to illustrate stl containers & iterators

/*************************************************************************
 * AUTHOR     : First Last
 * HW15       : stl containers & iterators
 * CLASS      : CS 1C
 * SECTION    : Date & Time
*************************************************************************/

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

// function & class definitions go into hw15.cpp:

// hw15.cpp

namespace hw15 {

//
// list conainter, iterator example code adapted from Chapter 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<typename Elem>
struct Link
{
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem  val;     // the value
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val{v}, prev{p}, succ{s} { }
};

//--Q#3-------------------------------------------------------------------------

template<typename Elem>
class list
{
    // representation and implementation details
public:
    class iterator;         // forward declaration of member type: class iterator
    class const_iterator;   // forward declaration of member type: class const_iterator

    list() : first(new Link<Elem>()), last{first} { }
    ~list()
    {
        while (first != last)
        {
            Link<Elem> *next = first->succ;
            delete first;
            first = next;
        }
        delete last;
    }

    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element

    const_iterator begin() const;   // constant iterator to first element
    const_iterator end() const;     // constant iterator to one beyond last element 

    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list

    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v); // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();      // the first element
    Elem& back();       // the last element

    Link<Elem>* first;
    Link<Elem>* last;   // one-beyond-the-last link
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::iterator // definition for class iterator
{
    Link<Elem>* curr;   // current node
public:
    iterator(Link<Elem>* p) : curr{p} { }
    iterator& operator++() // forward
    {
        curr++;                // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    iterator& operator--() // backwards
    {
        --curr;                // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    Elem& operator*() // get value (dereference)
    {
                        // temp, replace when defining function
        return curr->val; // included so that incomplete lab code will compile
    }

    bool operator==(const iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
    {
        if(curr->val == rhs.curr->val)
            return true;
                      // temp, replace when defining function
        return false; // included so that incomplete lab code will compile
    }
    bool operator!=(const iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
    {
        if(curr->val != rhs.curr->val)
            return true;
                      // temp, replace when defining function
        return false; // included so that incomplete lab code will compile
    }
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::const_iterator // definition for class const_iterator
{
    const Link<Elem>* curr;   // current node
                              // node pointed to by curr is immutable (i.e. can't be changed)
                              // fine to modify curr pointer itself (i.e. pointer value stored in curr)
                              // refer to const correctness reading
public:

    // add missing constructor, overloaded ++, --, *, ==, != operators here

    const_iterator(Link<Elem>* p) : curr{p} { }
    const_iterator& operator++() const // forward
    {
        curr++;                // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    const_iterator& operator--() const // backwards
    {
        --curr;                // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    Elem& operator*() const // get value (dereference)
    {
                        // temp, replace when defining function
        return curr->val; // included so that incomplete lab code will compile
    }

    bool operator==(const const_iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
    {
        if(curr->val == rhs->curr->val)
            return true;
                      // temp, replace when defining function
        return false; // included so that incomplete lab code will compile
    }
    bool operator!=(const const_iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
    {
        if(curr->val != rhs->curr->val)
            return true;
                      // temp, replace when defining function
        return false; // included so that incomplete lab code will compile
    }
};

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
{ 
    return iterator(first); 
}

//--Q#3-------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::const_iterator list<Elem>::begin() const  // constant iterator to first element
{ 
    return const_iterator(first);
}

//------------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::iterator list<Elem>::end() // iterator to one beyond last element
{ 
    return iterator(last);
}

//--Q#3-------------------------------------------------------------------------

template<typename Elem> 
typename list<Elem>::const_iterator list<Elem>::end() const  // constant iterator to last element
{ 
    return const_iterator(last);
}

//------------------------------------------------------------------------------

template<typename Elem> 
void list<Elem>::push_front(const Elem& v) // insert v at front
{
    first = new Link<Elem>(v,0,first);
}

//
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--Q#5-------------------------------------------------------------------------

double* low_doubles(double* first, double* last)
    // return a pointer to the element in [first,last) that has the lowest value
{
    double l = -1;
    double* low;
    for(double* p = first; p!=last; ++p)
        if (*p < l) { low = p; l = *p; }
    return low;
}

//--Q#5-------------------------------------------------------------------------

// implement templated low algorithm here
template<typename T>
T low(T first, T last)
{
    int l = -1;
    T low = first;
    for(T p = first; p!=last; ++p)
        if (*p < *low) { low = p; l = *p; }
    return low;
}

//------------------------------------------------------------------------------

} // hw15

//------------------------------------------------------------------------------

using namespace hw15;

//
// list conainter, iterator example code adapted from Chapter 20.4
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*           Running HW15             * " << endl;
	cout << "*      Programmed by Jade Tran       * " << endl;
	cout << "*       CS1C TTh & 12:50-2:50        * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

	// Q#3,4 - containters & iterators

    list<int> myList;
    int size = 5;
    int x;
    while (size > 0 && cin >> x) {
        myList.push_front(x);
        size--;
    } 

	// Q#5 - low_doubles algorithm

    double d[] = {1,2,3,4,5,-99.25,100,10,500.123,5};       // init array of doubles
    vector<double> v = {1,2,3,4,5,-99.25,100,10,500.123,5}; // init identical vector of doubles

    double* lowa = low_doubles(&d[0], &d[9]); // min of array
    cout << endl << "low_doubles alg: double array min value is " << *lowa << endl << endl;

    double* middle = &v[0] + v.size()/2;
    //double* lowv1 = low_doubles(&v[0], middle);          // min of vector first half - segmentation fault - explaination below
    double* lowv2 = low_doubles(middle, &v[0]+v.size()); // min of vector second half
    //cout << "low_doubles alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low_doubles alg: double vector min value second half is " << *lowv2 << endl << endl;

	// Q#5 - low algorithm

    // NOTE: uncomment code below once low algorithm definition is complete

    lowa = low(&d[0], &d[9]); // min of array
    cout << "low alg: double array min value is " << *lowa << endl << endl;

    //lowv1 = low(&v[0], middle);          // min of vector first half
    lowv2 = low(middle, &v[0]+v.size()); // min of vector second half
    //cout << "low alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low alg: double vector min value second half is " << *lowv2 << endl << endl;

    list<int>::iterator mylist_first = myList.begin();
    list<int>::iterator mylist_last = myList.end();
   
    list<int>::iterator p = low(mylist_first, mylist_last); // min of list        // no matching function - low()
    if (p==myList.end())    // did we reach the end? - no as the list only has 1 element
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << endl;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#1
// What is an stl container?
// The STL contains sequence containers and associative containers. The containers are objects that store data.
// The standard associative containers are set, multiset, map, multimap, hash_set, hash_map, hash_multiset and 
// hash_multimap. There are also container adaptors queue, priority_queue, and stack, that are containers with 
// specific interface, using other containers as implementation.
//
// stl iterator? 
// The STL implements five different types of iterators. These are input iterators (that can only be used to 
// read a sequence of values), output iterators (that can only be used to write a sequence of values), forward 
// iterators (that can be read, written to, and move forward), bidirectional iterators (that are like forward 
// iterators, but can also move backwards) and random-access iterators (that can move freely any number of 
// steps in one operation).
// A fundamental STL concept is a range which is a pair of iterators that designate the beginning and end of 
// the computation, and most of the library's algorithmic templates that operate on data structures have 
// interfaces that use ranges. 
// Iterators are the major feature that allow the generality of the STL. 
// For example, an algorithm to reverse a sequence can be implemented using bidirectional iterators, and 
// then the same implementation can be used on lists, vectors and deques. User-created containers only have 
// to provide an iterator that implements one of the five standard iterator interfaces, and all the algorithms
// provided in the STL can be used on the container.
//
// stl algorithm? 
// A large number of algorithms to perform activities such as searching and sorting are provided in the STL, 
// each implemented to require a certain level of iterator (and therefore will work on any container that 
// provides an interface by iterators). Searching algorithms like binary_search and lower_bound use binary
// search and like sorting algorithms require that the type of data must implement comparison operator < or 
// custom comparator function must be specified; such comparison operator or comparator function must guarantee
// strict weak ordering. Apart from these, algorithms are provided for making heap from a range of elements,
//  generating lexicographically ordered permutations of a range of elements, merge sorted ranges and perform
// union, intersection, difference of sorted ranges.
// Example: std :: unique algorithm. This std :: unique is an  Algorithm that removes all consecutive duplicate
// elements from a given range. For example, we have an array of elements and we want to delete the conjugative
// elements. std::unique  removes consecutive duplicate elements. For executing this  we should sort the given
// range, and  make sure that duplicate elements are at their  consecutive positions.
//
// std::vector<int> vec1 = {1,6,3,5,4,8,5,2,3,9,8,6,7,1,5,9,0};
// 
// std::sort(vec1.begin(), vec1.end());             // Sorting of element to bring conjugative position 
// std::vector<int>::iterator vec2;
//
// vec2 = std::unique(vec1.begin(), vec1.end());    // Overriding the duplicate element
// vec1.erase(vec2, vec1.end());
//
// std ::cout<< " after deletion : ";
// for(int i=0; i < vec1.size(); i++)
//     std::cout << vec1.at(i) << ' ';
// return 0;
//
// Q#2
// how the iterator architecture makes it possible to decouple algorithms from containers. Why is this important? 
// According to Alexander Stepanov, iterators are central to the use of algorithms, 
// because they decouple the algorithms from the specific type of container that the algorithm might currently 
// be working with. This means that you can describe the algorithm without worrying about the particular sequence
// it is operating on. More generally, any code that you write using iterators is decoupled from the data structure
// that the code is manipulating, and thus your code is more general and reusable.
//
// Q#5
// In what ways are the algorithms low_doubles and low similar? different? 
// As a template feature allows you to write generic programs; therefore, low function works with any type
// of data whereas low_doubles function works with the specific types mentioned while writing a program.
// Both low_doubles and low functions accept any number of parameters.
//
// In main the output for finding the lowest value in the first half of vector v differs for low_doubles vs low.
// What is happening here?
// When calling low_doubles() function, the function intentionally set -1 as the lowest value in the list, mylist, 
// which, at the same time, isn't an element of the list. Therefore, when searching for the lowest value in the
// first half of the list, the pointer, low, now is pointing to a non-existed value; therefore, it causes segmentation
// fault which crashes the program.
// Meanwhile, when searching the second half, the function returns a lowest value as it contains -99.25 that is
// smaller than -1, which is intentionally set as the lowest value in the list.
//
// Similarly, when using low() function to find the lowest value for the first half of the list, it causes segmentation
// fault as the pointer returning from the function is a dangling pointer pointing to a non-existed value in the list.
// For the second half elements, it returns a lowest value, -99.25, as it is smaller than -1. 
// 
// list<int>::iterator p = low(mylist_first, mylist_last); // min of list 
//
// Here, insteading of passing static variables like double, we are passing pointers, specially iterator, to the function.
// However, again intentionally the list previously is initialized by provoking push_front() function.
//
// while (size > 0 && cin >> x) {
//         myList.push_front(x);
//         size--;
//     } 
//
// Notice that push_front() keeps over-writing the first element: 
//      first = new Link<Elem>(v,0,first);
// With that being said, the list only has one element. Therefore, the function will always return that element.

