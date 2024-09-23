//
//  main.cpp
//  Binary Heap Tree validity check
//
//  Modified by Shruthi on 04/04/19
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>


using namespace std;

class BinaryHeap
{
public:
    BinaryHeap();                     // Construction
    bool less(int i, int j);
    bool swim(int k);
    bool sink(int k);
    bool heapTest(int *pq, int N);
    int N = 0;
    int *pq;
    int capacity = 100;
    
};


// Initialize the class
BinaryHeap::BinaryHeap()
{
    
    pq = new int[capacity];
    cout << "A new priority queue with " <<  capacity << " capacity was created...!" << endl ;
}


bool BinaryHeap::swim(int k)
{
    
    bool ret = NULL;
    while (k > 1)
    {
        if(!less(k/2, k)){
            k = k/2;
            ret = true;
        }
        else{
            ret = false;
            break;
        }
    }
    return ret;
}


bool BinaryHeap::less(int i, int j)
{
    if (pq[i] < pq[j])
        return true;
    return false;
}

bool BinaryHeap::heapTest(int *pq, int Num) {
    //cout << "HeapTest\n";
    bool decision = true;
    if(Num > N) {
        cout << "Value exceeded Array elements size\n";
        return false;
    }
    else{
        //Checking if parents are greater from (1 - Num) range SubArray
        for(int j=Num; j>1; j--) {
            //cout << "for " << j << endl;
            decision = swim(j);
            if(decision) continue;
            else break;
        }
    }
    return decision;
}

// The program lunches here
int main( )
{
    BinaryHeap BH;
    int range = 0;
    int A[] = {4, 50, 45, 35, 37, 25, 33, 34, 89, 0, 58, 45};
    BH.pq = A;
    BH.N = sizeof(A)/sizeof(A[0]);
    while(range >= 0) {
        cout << "\nEnter Range :";
        cin >> range;
        if(range < 0 ) break;
        if (BH.heapTest(A, range)) cout << "heapTest(A," << range << ") : True \n";
        else cout << "heapTest(A," << range << ") : False \n";
    }
}




