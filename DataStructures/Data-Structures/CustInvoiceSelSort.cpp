//Shruthi Madishetty
// Created on Mar-07

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  20

using namespace std;

struct invoice
{
    unsigned int custNo;
    unsigned short amount;
    string owner;
};

string RandomStr();  // A function to randomly generate 6  chars strings.
void swap(invoice A[], int i, int min);
bool small(invoice A[], int a, int b);
void print(invoice A[]);
void fillRandom(invoice A[], int size);
void sort(char option);


void swap(invoice A[], int i, int min)
{
    invoice tmp = A[i];
    A[i]=A[min];
    A[min]=tmp;
}

void fillRandom(invoice A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i].owner=RandomStr();
        A[i].custNo=100 + rand() % 9900; // 100 to 10000
        A[i].amount = 100 + rand() % 1900; // 100 to 2000
    }
}

void print(invoice A[])
{
    for (int i = 0; i < N; i++)
        cout << A[i].owner << " : " << A[i].custNo << " : $ " << A[i].amount << endl;
    cout << endl;
}

bool small(invoice A[],int a, int b, char option)
{
    if(option == 'c') {
        if (A[a].custNo < A[b].custNo) return true;
    }
    else if (option == 'a') {
        cout << A[a].amount;
        if (A[a].amount < A[b].amount) return true;
    }
    else if (option == 'o') {
        if (A[a].owner < A[b].owner) return true;
    }
    return false;
}

void sort(invoice *A, char option) {
    
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i+1; j < N; j++)
        {
            if ( small(A, j, min,option) == true) min = j;
        }
        swap(A, i, min);
    }
    
}

string RandomStr()
{
    string AddMe="012";
    for (int j=0; j <8; j++)
    {
        AddMe[j]=rand() % 26 + 65;
    }
    return AddMe;
}

int main(int argc, const char * argv[])
{
    invoice *A = new invoice[N];
    fillRandom(A,N);
    //print(A);
    char sel = ' ';
    print(A);
    
    //char option = sel;
    while(sel != 'e') {
        cout << "\n(c)ustomer No Sort \n(a)mount sort \n" ;
        cout << "(o)wner sort \n(e)xit\n";
        cin >> sel;
        
        switch(sel)
        {
            case 'c':
                sort(A, 'c');
                print(A);
                break;
            case 'a':
                sort(A, 'a');
                print(A);
                break;
            case 'o':
                sort(A,'o');
                print(A);
                break;
            default:
                break;
        }
    }
}

