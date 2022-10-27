#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>
#include <iomanip>
#include <memory>
#include <exception>      // std::exception
using namespace std;

// Define the default size of the queue
#define SIZE 10

class ExceptionQueueIsFull: public std::exception  { public: const char* what() const noexcept override {return "= Ooops! The queue currently is full. Can't add more items into the queue!\n";} };
class ExceptionQueueIsEmpty: public std::exception { public: const char* what() const noexcept override {return "= Ooops! The queue currently is empty. Can't remove an item from an empty queue!\n";} };

template <typename Type>
class queue {
public:

	/* Constructor */
    queue(int queueSize = SIZE);
      
    /* Copy constructor */
    queue(const queue<Type>& otherQueue);               

	/* Copy assignment operator */
    queue<Type>& operator=(const queue<Type>& otherQueue);         

    /* Move contructor */
    queue(queue<Type>&& otherQueue) noexcept;                     

	/* Move assignment operator */
    queue<Type>& operator=(queue<Type>&& otherQueue) noexcept;   

    /* Destructor */
    ~queue(); 

	/* Function to determine whether the queue is empty.
	 * Returns true if the current queue is empty. Otherwise, return false.
	 */
    bool isEmpty() const;
                    
    /* Function to determine whether the queue is full.
	 * Returns true if the current queue is full. Otherwise, return false.
	 */
    bool isFull() const;
      
	/* Function to initialize the queue to an empty state.
	 * Postcondition: The queue is empty.
	 */
    void initialize_queue();
     
	/* Function to return the first element of the queue.
	 * Precondition:  The queue exists and is not empty.
	 * Postcondition: If the queue is empty, the program terminates; 
	 * 			   	  otherwise, the first element of the queue is returned.  
	 */
    Type front() const;
      
    /* Function to return the last element of the queue.
	 * Precondition:  The queue exists and is not empty.
	 * Postcondition: If the queue is empty, the program terminates; 
	 * 			   	  otherwise, the last element of the queue is returned.  
	 */
    Type back() const;

     /* Function to return the queue's current size.
	 * Postcondition: If the queue is empty, return 0; 
	 * 			   	  otherwise, return the current size.  
	 */
    int size() const { return count; }
      
	/* Function to add queueElement to the queue.
	* Precondition:  The queue exists and is not full.
	* Postcondition: The queue is changed and queueElement
	* 			   	 is added to the queue.
	*/
    void enqueue(const Type& queueElement);
      
	/* Function to remove the first element of the queue.
	* Precondition:  The queue exists and is not full.
	* Postcondition: The queue is changed and the first 
	* 			   	 element is removed from the queue.
	*/
    void dequeue();
      
private:
    int maxQueueSize; // the maximum queue size
    int count;        // the number of elements in the queue
    int first;   	  // index "first" point to the first element of the queue
    int last;    	  // index "last" point to the last element of the queue

    std::shared_ptr<Type[]> list;	// unique pointer array stores the elements of the queue.

	//Type *pList;       //pointer to the array that holds 
                      //  the queue elements 
};

/* Constructor */
template <class Type>
queue<Type>::queue(int queueSize)   
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = SIZE;
    }
    else
        maxQueueSize = queueSize;   
                                    
    first = 0;                 		
    last = maxQueueSize - 1;   		
    count = 0;

    list = make_unique<Type[]>(maxQueueSize);
} 

/* Destructor */
template <class Type>
queue<Type>::~queue()   
{
    //delete [] list;
    list.reset();
} 

/* Copy constructor */
template <class Type>
queue<Type>::queue(const queue<Type>& otherQueue)
    : maxQueueSize{otherQueue.maxQueueSize}, count{otherQueue.count},
        first{otherQueue.first}, last{otherQueue.last}
{

    list = make_unique<Type[]>(maxQueueSize);

    // init array
    for( int i = 0; i < otherQueue.count; i++ ) list[i] = otherQueue.list[i];

}

/* Copy assignment constructor */
template <class Type>
queue<Type>& queue<Type>::operator=(const queue<Type>& otherQueue)
{

    if( this != &otherQueue ) {
        maxQueueSize = otherQueue.maxQueueSize;
        count = otherQueue.count;
        first = otherQueue.first;
        last = otherQueue.last;

        list.reset();
        list = make_unique<Type[]>(maxQueueSize);

        // init array
        for( int i = 0; i < otherQueue.count; i++ ) 
            list[i] = otherQueue.list[i];
    }

    return *this;
}

/* Move contructor */
template <class Type>
queue<Type>::queue(queue<Type>&& otherQueue) noexcept
    : maxQueueSize{0}, count{0},
        first{0}, last{0} {
    
    maxQueueSize = otherQueue.maxQueueSize;
    count = otherQueue.count;
    first = otherQueue.first;
    last = otherQueue.last;

    list = make_unique<Type[]>(maxQueueSize);

    // init array
    for( int i = 0; i < count; i++ ) list[i] = otherQueue.list[i];

    // now that source vector contents have been moved, empty the old object
    otherQueue.maxQueueSize = 0;
    otherQueue.count = 0;
    otherQueue.first = 0;
    otherQueue.last = 0;
    otherQueue.list = NULL;                    
}               

/* Move assignment operator */
template <class Type>
queue<Type>& queue<Type>::operator=(queue<Type>&& otherQueue) noexcept {

    if( this != &otherQueue ) {
        list.reset();      // deallocate old space

        maxQueueSize = otherQueue.maxQueueSize;
        count = otherQueue.count;
        first = otherQueue.first;
        last = otherQueue.last;

        list = make_unique<Type[]>(maxQueueSize);

        // init array
        for( int i = 0; i < otherQueue.count; i++ ) 
            list[i] = otherQueue.list[i];

        // now that source vector contents have been moved, empty the old object
        otherQueue.maxQueueSize = 0;
        otherQueue.count = 0;
        otherQueue.first = 0;
        otherQueue.last = 0;
        otherQueue.list = NULL;       
    }

    return *this;         // return a self-reference
}

/* Function checks if empty */
template <class Type>
bool queue<Type>::isEmpty() const
{
    return (count == 0);
} 

/* Function checks if full */
template <class Type>
bool queue<Type>::isFull() const
{
    return (count == maxQueueSize);
} 

/* Function initialize the queue */
template <class Type>
void queue<Type>::initialize_queue()
{
    first = 0;
    last = maxQueueSize - 1;
    count = 0;
} 

/* Function returns the "front" element */
template <class Type>
Type queue<Type>::front() const
{
    assert(!isEmpty());
    return list[first]; 
} 

/* Function returns the "back" element */
template <class Type>
Type queue<Type>::back() const
{
    assert(!isEmpty());
    return list[last];
} 

/* Function adds an element to the queue */
template <class Type>
void queue<Type>::enqueue(const Type& newElement)
{
    if (!isFull())
    {   
        last = (last + 1) % maxQueueSize; //use mod operator to advance last  
                            			  //because the array is circular
        count++;
		list[last] = newElement; 	  	  // value symmantics - store a copy of newElement in our queue
										  // list + last (computes an offset)
    }
    else
        throw ExceptionQueueIsFull(); 
} 

/* Function removes an element to the queue */
template <class Type>
void queue<Type>::dequeue()
{
    
	if (!isEmpty())
    {   
        count--;
        first = (first + 1) % maxQueueSize; //use the
                        //mod operator to advance queueFront 
                        //because the array is circular 
    }
    else
        throw ExceptionQueueIsEmpty();
    
} 

#endif /* QUEUE_H_ */