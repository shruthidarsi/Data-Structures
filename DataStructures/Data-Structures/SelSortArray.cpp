// Mutlu Mete
// Selection Sort in Randomly genereated integer array


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  10000
// In Class Practice Work: Run selection sort on 1000, 2000, 4000 items 3 times

#include <ctime>

using namespace std;

void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);

int main(int argc, const char * argv[])
{
	clock_t start, stop;
	double totalTime;
	int  A[N]={0};
	fillRandom(A,N);
	//print(A);

	start = clock();
	// Selection sort
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( small(A[j], A[min]) == true) min = j;
		}
		swap(A, i, min);
	}
	stop = clock();
	totalTime = (stop - start) / (double)CLOCKS_PER_SEC;
	cout << "Time passed: " << totalTime << endl;
	//print(A);
}

void swap(int A[], int i, int min)
{
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;
}

void fillRandom(int A[], int size)
{
	for (int i = 0; i < N; i++)
		A[i]=rand() % 50;
}

void print(int A[])
{
	for (int i = 0; i < N; i++)
		cout << A[i] << ", ";
	cout << endl;
}

bool small(int a, int b)
{
  if (a < b) return true;
  return false;
}