// Shruthi Madishetty
// Tukey's Ninther Algorith Implementation for Pivot value
//File created on 03/28/2019


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <map>
#include <ctime>
#include <cmath>
#define N  128000

using namespace std;

void swap(char A[], int i, int min);
bool small(char a, char b);
void print(char A[]);
void fillRandom(char A[], int size);
const char stringarr[] = "abcdefghijklmnopqrstuvwxyz";
void sort(char A[], int lo, int hi);
int partition(char A[], int lo, int hi);
void TukeySort(char B[], char tukeyArr[], map<int,char> pivotmap);
char median(char a, char b, char c);

int main(int argc, const char * argv[])
{
    char  A[N]={0};
    char B[N]={0};
    char tukeyArr[9] = {0};
    map<int,char> pivotmap;
    clock_t start, stop;
    double qTotalTime, tkTotalTime, qSum=0, tkSum = 0, qAvg = 0, tkAvg = 0;
    long double qnumerator=0, tknumerator=0  ;
    int nTimes = 50;
    double qTime[50]={0}, tkTime[50] = {0};
    
    //Shuffle(A); shuffle  the array. commentted out for now
    for (int j=0; j<nTimes; j++) {
        fillRandom(A,N);
        for(int i=0;i<N;i++) B[i] = A[i];
        //For Normal Qsort
        start = clock();
        sort(A, 0, N-1);
        stop = clock();
        qTotalTime = (stop - start) / (double)CLOCKS_PER_SEC;
        qTime[j] = qTotalTime;
        
        qSum += qTotalTime;
        
        //For Tukeys Ninther Qsort
        start = clock();
        TukeySort(B, tukeyArr, pivotmap);
        stop = clock();
        tkTotalTime = (stop - start) / (double)CLOCKS_PER_SEC;
        tkTime[j] = tkTotalTime;
        tkSum += tkTotalTime;
    }
    qAvg = qSum/nTimes;
    tkAvg = tkSum/nTimes;
    for (int k=0; k<nTimes; k++) {
        qnumerator += ((qTime[k]-qAvg) * (qTime[k]-qAvg));
        tknumerator += ((tkTime[k]-tkAvg) * (tkTime[k]-tkAvg));
    }
    
    //Formula for Standard Deviation time = Sqrt[(xi-xm)/(N-1)] for i=0..49, xm=mean(or)avg
    cout << "Average time : \n";
    cout << "Q-Sort :\t\t"<< qAvg << endl;
    cout << "Tukey's-QSort :\t" << tkAvg << endl;
    cout << "\nStandard Deviation time:\n" ;
    cout << "Q-Sort :\t\t"<< sqrt(qnumerator/(nTimes-1)) << endl;
    cout << "Tukey's-QSort :\t" << sqrt(tknumerator/(nTimes-1)) << endl;
    //Formula = Diff Between Values / Value being compared to
    if(qAvg > tkAvg)
        cout << "\nTukey Faster by : " << ((qAvg-tkAvg)/tkAvg)*100 << "%" << endl;
    else
        cout << "\nQsort Faster by : " << ((tkAvg-qAvg)/qAvg)*100 << "%" << endl;
    
    cout << endl;
}

void sort(char A[], int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(A, lo, hi);
    sort(A, lo, j-1);
    sort(A, j+1, hi);
}

int partition(char A[], int lo, int hi)
{
    int i = lo, j = hi+1;
    while (true)
    {
        while (small(A[++i], A[lo]))  // find item on left to swap
            if (i == hi) break;
        
        while (small(A[lo], A[--j]))  // find item on right to swap
            if (j == lo) break;
        
        if (i >= j) break;    //check if pointers cross
        swap(A, i, j);
    }
    swap(A, lo, j);
    return j;            // return index of item now known to be in place
}

void swap(char A[], int i, int min)
{
    char tmp= A[i];
    A[i]=A[min];
    A[min]=tmp;
}

void fillRandom(char A[], int size)
{
    for (int i = 0; i < N; i++)
        A[i]= stringarr[rand()% (sizeof(stringarr) - 1)];
}

void print(char A[])
{
    for (int i = 0; i < N; i++)
        cout << A[i] << ", ";
}

bool small(char a, char b)
{
    if (a <= b) return true;
    return false;
}

void TukeySort(char B[], char tukeyArr[], map<int,char> pivotmap)
{
    int tval = 0;
    int indexval = 0;
    for(int i=0; i<9; i++) {
        tukeyArr[i] = B[tval];
        //cout << "tukeyArr[" << i << "] : " << tukeyArr[i] << endl;
        pivotmap.insert(pair<int,char>(tval, B[tval]));
        tval += (N/9);
        //cout << tval << endl;
    }
    char m1 = median(tukeyArr[0], tukeyArr[1], tukeyArr[2]);
    char m2 = median(tukeyArr[3], tukeyArr[4], tukeyArr[5]);
    char m3 = median(tukeyArr[6], tukeyArr[7], tukeyArr[8]);
    //cout << m1 << ", " << m2 << ", " << m3 << endl;
    char pivot = median(m1, m2, m3);
    //    cout << "Tukey's Ninther PIVOT = " << pivot << endl;
    map<int, char>::iterator it = pivotmap.begin();
    while(it != pivotmap.end()) {
        //cout << "it ---- " << it->second << endl;
        if(it->second == pivot) indexval = it->first;
        ++it;
    }
    //cout << "PIVOT Before ==> B[0] : " << B[0] << " , B[" << indexval << "] : "<< B[indexval] ;
    swap(B, 0, indexval);
    //cout << "PIVOT After  ==> B[0] : " << B[0] << " , B[" << indexval << "] : "<< B[indexval];
    sort(B, 0, N-1);
}

char median(char a, char b, char c) {
    if((a>=b && b>=c ) || (c>=b && b>=a)) return b;
    else if((b>=c && c>=a ) || (a>=c && c>=b)) return c;
    else if((b>=a && a>=c) || (c>=a && a>=b)) return a;
    else return NULL;
}


