#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle() { l=0; w=0; }
    Rectangle (int l, int w) : l{l}, w{w} {} 
    ~Rectangle() {}

    /* Setters.
     * Pre-condition: int variables.
     * Post-condition: private member variables must be assigned to valid variables.
     */
    void set_l(int temp_l);
    void set_w(int temp_w);

    /* Getters.
     * Pre-condition: <none>
     * Post-condition: return all the object's private data accoridng to the function.
     */	
    int get_l() const;
    int get_w() const;
    
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
    int l; // length 
    int w; // width 
}; 

#endif /* RECTANGLE_H_ */
