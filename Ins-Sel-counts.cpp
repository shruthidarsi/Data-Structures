// Comparison of Selectioin and Insertion Sort in Randomly genereated integer in dynamicall crated arrays

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>

#define N1 8000
#define N2 16000

using namespace std;

void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);
void InsSort(int A[], int size);
void SelSort(int A[], int size);
void sortArrays(int size);
int scount, ccount;

int main(int argc, const char * argv[])
{
    int* A;
    int* B;
    clock_t start, stop;
    double totalTime;
    int size = 8000;
    cout << "N" << "\t" << "IS" << "\t" << "SS" << endl;
    
    while (size <= 16000)
    {
        A = new int[size];
        B = new int[size];
        fillRandom(A,size);
        for (int i =0; i <size; i++) B[i]= A[i]; // deep copy
        
        cout << size << "\t";
        // Insertion sort
        start = clock();
        InsSort(A, size);
        cout << "\nInsertion Sort - compares = " << ccount << endl;
        cout << "Insertion Sort - swaps = " << scount << endl;
        
        stop = clock();
        totalTime = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << totalTime << "\t" ;
        cout << endl;
        scount = ccount = 0;
        // Selection sort
        start = clock();
        SelSort(B, size);
        cout << "Selection Sort - compares = " << ccount << endl;
        cout << "Selection Sort - swaps = " << scount << endl;
        stop = clock();
        totalTime = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << totalTime << endl;
        cout << endl;
        
        delete []A;
        delete []B;
        size = 2 * size ;
        scount = ccount = 0;
    }
}



void SelSort(int A[], int size)
{
    // Selection sort
    for (int i = 0; i < size; i++)
    {                                 // Swap a[i] with smallest entry in a[i+1...N).
        int min = i;                 // index of minimal entr.
        for (int j = i+1; j < size; j++)
        {
            if ( small(A[j], A[min]) == true) {
                min = j;
            }
        }
        swap(A, i, min);
    }
}

void InsSort(int A[], int size)
{
    // Insertion sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
            if ( small(A[j], A[j-1]) == true){ // compare
                swap(A, j, j-1); // exchange or swap
            }
            else break;
    }
    
}

bool small(int a, int b)
{
    ccount++;
    if (a < b) return true;
    return false;
    
}

void swap(int A[], int i, int min)
{
    int tmp= A[i];
    A[i]=A[min];
    A[min]=tmp;
    scount++;
}


void fillRandom(int A[], int size)
{
    for (int i = 0; i < size; i++)
        A[i]=rand() % 10000 - 5000;
}


