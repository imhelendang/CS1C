#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

class Triangle : public Shape { 
public:
    Triangle() {}
    Triangle (int a, int b, int c) : a{a}, b{b}, c{c} {} 
    ~Triangle() {}

    /* Setters.
     * Pre-condition: int variables.
     * Post-condition: private member variables must be assigned to valid variables.
     */
    void set_a(int temp_a);
    void set_b(int temp_b);
    void set_c(int temp_c);

    /* Getters.
     * Pre-condition: <none>
     * Post-condition: return all the object's private data accoridng to the function.
     */	
    int get_a() const;
    int get_b() const;
    int get_c() const;

    /* calcPerimeter.
     * Pre-condition: <none>
     * Post-condition: return the result.
     */	
    int calcPerimeter() const override;

    /* calcArea.
     * Pre-condition: <none>
     * Post-condition: return the result.
     */	
    int calcArea() const override;

    /* print().
     * Pre-condition: <none>
     * Post-condition: display the data nicely.
     */	
    void print();

private: 
    int a;
    int b;
    int c;  
}; 

#endif /* TRIANGLE_H_ */
