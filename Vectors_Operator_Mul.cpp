#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html


using namespace std;

struct item
{
    unsigned int index;
    int data;
    item *next;
};
// Maintains index,data association for the vector. Indexes are kept ordered.
class Vector
{
public:
    Vector();                                   // Construction
    bool add(unsigned int index, int data);        // Adds a new item to vector
    void ListAll();                             // List all items of vector, starting with the first ITEM
    unsigned short getSize();                        // returns the size of the vector
    void setSize(unsigned int size);
    Vector operator * (Vector&);
    item *getFirst();         // returns the pointer, "first"
    
private:
    item *first;                    // A pointer to show the first node
    item *last;                     // A pointer to show the last node
    unsigned short size;            // how many items vector has
    unsigned short compSize;        // non-zero items vector has
};

// Initialize the class
Vector::Vector()
{
    first = last = NULL;
    size = 0 ;
}

unsigned short Vector::getSize()
{
    return size;
}

item * Vector::getFirst()
{
    return first;
}

void Vector::ListAll()             // List all items of vector, starting with the first ITEM
{
    item *it = first;
    int  cnt = 0;
    
    while (it != NULL ) {
        cout << it->index << ":";
        cout << it->data << " ";
        it = it->next;
        cnt++;
    }
    cout << endl;
}

Vector Vector::operator* (Vector &param) {
    Vector mulVector;
    item *itA = first;
    item *itB = param.getFirst();
    
    while (itA != NULL || itB != NULL )
    {
        if (itA != NULL && itB != NULL )
        {
            if (itA->index < itB->index)
            {
                itA = itA->next;
            }
            else if (itA->index > itB->index)
            {
                itB = itB->next;
            }
            else
            {
                mulVector.add(itA->index, itB->data * itA->data  ); //multiply the values if non-zero and equal indecies are found
                itA = itA->next;
                itB = itB->next;
            }
        }
        else  if (itA != NULL )
        {
            itA = itA->next;
        }
        else if  (itB != NULL )
        {
            itB = itB->next;
        }
    }
    mulVector.setSize(size);
    
    //temp.x = x + param.x;
    //temp.y = y + param.y;
    return mulVector;
}

void Vector::setSize(unsigned int size)
{
    this->size = size;
}

bool Vector::add(unsigned int index, int data)        // Adds a new item to Vector, to the end
{
    item *NewItemPtr = new item;            //  dynamically create a new struct/item
    if ( NewItemPtr == NULL) return false;  // not enought memory
    
    NewItemPtr->index = index;                  // we append, add to end of list
    NewItemPtr->data = data;
    NewItemPtr->next = NULL;
    compSize++;
    //size=index+1;
    
    if (last == NULL)                     // first item to be added
    {
        first = last = NewItemPtr;
    }
    else
    {
        last->next = NewItemPtr;
        last = NewItemPtr;
    }
    return true;    // Yeah, added.
}

int main(int argc, const char * argv[])
{
    Vector A,B, mulVector;
    int locA = 0, locB = 0 ;
    int data = 0;
    for (int i=0; i< 5; i++) // adds 20 items.
    {
        //cout<<"rand" <<rand() % 2 + 1 <<endl;
        locA = locA + rand() % 5 + 1;
        data = rand() % 50 + 30;
        A.add(locA, data);
        
        locB = locB + rand() % 5 + 1;
        data = rand() % 50 + 30;
        B.add(locB, data);
    }
    
    A.setSize(95);
    B.setSize(95);
    cout << " items found in A ...";
    A.ListAll();
    cout << A.getSize() << " items found..." << endl;
    
    cout << " items found in B ...";
    B.ListAll();
    cout << B.getSize() << " items found..." << endl;
    
    mulVector = A * B;
    cout << "Result Vector for A*B is :::: ";
    mulVector.ListAll();
    cout << mulVector.getSize() << " items found..." << endl;
}


