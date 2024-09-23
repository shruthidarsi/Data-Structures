//
//  main.cpp
//  Binary 3-way Heap Tree for Priority Queue
//
//  Created by Shruthi Pavan



#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>      // std::setw
//#define N  20


using namespace std;

class BinaryHeap
{
public:
    BinaryHeap();                     // Construction
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
    bool isEmpty();
    int size();
    void insert(int v);
    int delMax();
    void ListArray();
    void printT(int x, int id);
    int findMax(int i, int j, int k);
    
private:
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

void BinaryHeap::ListArray()
{
    for (int i=1; i <= N; i++) // Remember we have "size" items
    {
        cout << pq[i] << ", ";
    }
}

void BinaryHeap::swim(int k)
{
    while (k > 1 && less((k+1)/3, k))
    {
        exch((k+1)/3, k);
        k = (k+1)/3;
    }
}

bool BinaryHeap::isEmpty()
{  return N == 0;  }

int BinaryHeap::size()
{  return N;  }

void BinaryHeap::insert(int v)
{
    pq[++N] = v;
    swim(N);
}

int BinaryHeap::delMax()
{
    int max = pq[1];
    exch(1, N--);
    pq[N+1] = NULL;
    sink(1);
    return max;
}

void BinaryHeap::sink(int k)
{
    //cout << 3*k-1 << endl;
    while ((3*k-1) <= N)
    {
        int j = 3*k-1;
        j = findMax(j, j+1, j+2);
        if (!less(k, j)) break;
        exch(k, j);
        k = j;
    }
}

int BinaryHeap:: findMax(int i, int j, int k) {
    if( (pq[i] > pq[j]) && (pq[i] > pq[k])) return i;
    else if( (pq[j] > pq[k]) && (pq[j] > pq[i])) return j;
    else return k;
}

bool BinaryHeap::less(int i, int j)
{
    if (pq[i] < pq[j])
        return true;
    return false;
}

void BinaryHeap::exch(int i, int j)
{
    int t = pq[i]; pq[i] = pq[j]; pq[j] = t;
}
//1-> 2, 3
//2-> 4, 5
//3-> 6, 7
void BinaryHeap::printT(int x, int id)
{
    if (x>N) return;
    
    printT(3*x+1,id+10);
    
    cout << setw(id) << ' ' << pq[x] << endl;
    
    printT(3*x,id+10);
    
    cout << setw(id) << ' ' << endl;
    
    printT(3*x-1,id+10);
}
// The program lunches here
int main( )
{
    BinaryHeap BH;
    for (int i=0; i < 20; i++)
        BH.insert( rand()%89 +10);
    
    BH.ListArray();
    cout<< "\n ------\n ";
    //cout << "Deleting Node " << "1"  << " = "<< BH.delMax();
    
    for ( int i=0; i<5; i++)
        cout << "\nDeleting Node " << (i+1)  << " = "<< BH.delMax() << endl;
    
    BH.printT(1,10);
    
}





