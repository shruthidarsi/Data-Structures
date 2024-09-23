// MMete
// Static Bag
// Jan 23, 2018
#include <iostream>

using namespace std;

int Bag[200];
int N=0;

void add(int x );
void ListBag();
int main()
{
    add(5);     add(25);     add(3);     add(8);
    ListBag();
}
void add(int x) {  Bag[N++]=x; }
void ListBag()
{
    for (int i = 0; i < N ; i++)
        cout << Bag[i] << ", ";
}
