#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

class Stack
{
public:
    Stack(int n);                // Construction
    void push(int num);        // Adds a new item to stack
    unsigned int pop();         // remove the head guy (the most recently added item)
    int getSize();
private:
    unsigned int *Fib;
    int size;            // how many items stack has
};

// Initialize the class
Stack::Stack(int n)
{
    size = n;
    Fib = new unsigned int[n];
}

void Stack::push(int num)
{
    Fib[ size++ ] = num;
    //cout << size;
}
unsigned int Stack::pop()
{
    return Fib[--size];
}

int Stack::getSize()
{
    return size;
}

int main(int argc, const char * argv[]) {
    Stack _stack(30);
    cout << "Fibonacci Series Stack";
    
    int a = 0 , b = 1, c ;
    for (int i = 0; i < 30 ; i++) {
        if(i == 0) _stack.push(a);
        if(i == 1) _stack.push(b);
        
        if( i > 1) {
            c = a+b;
            a = b;
            b = c;
            _stack.push(c);
        }
    }
    
    cout << "Push all fibonacci numbers with size of 30 is done" << endl << endl;
    
    for(int j=30; j>0; j--){
        cout << _stack.pop() << endl;
        
    }
}






