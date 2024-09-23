#include <iostream>

using namespace std;

int main()
{
    cout<<"Start of Pointers"<< endl;
    short int X = 3;
    short int *A = &X, *B = &X, *C = &X;
    
    cout << "X Value is :" << X << endl;
    cout << "(3*X) = " << (3*X) << endl;
    cout << "(A* + B* + C*) = " << (*A + *B + *C) <<endl;
    
    if( (3*X) == (*A+*B+*C)) {
        cout << "(3*X) == (*A+*B+*C)" <<endl;
    }
    else {
        cout << "(3*X) != (*A+*B+*C)"<< endl;
    }
    
    X += 5;
    
    //Increment X value by 5
    cout << "Latest X Value is = " << X << endl;
    cout << "Pointer A Latest value = " << *A << endl;
    cout << "Pointer B Latest value = " << *B << endl;
    cout << "Pointer C Latest value = " << *C << endl;

    return 0;
}
