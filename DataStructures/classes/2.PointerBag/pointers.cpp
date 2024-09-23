// MMete
// Pointer intro
// Jan 22, 2019

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;
struct stu
{
 string name;
 int id;
 string phone;
};
int main()
{
  stu A;
  A.name = "Amy";    A.id = 134; A.phone = "1-2-3";

  stu *ptr= NULL;
  ptr = &A ;

  // cout << " Name of A is " <<  (*ptr).name << endl ;

  cout << " Name of A is " <<   ptr->name << endl ;
  cout << " ID of A is " <<     ptr->id << endl ;
  cout << " Phone of A is " <<  ptr->phone << endl ;

  // (*ptr).name  is exactly same as ptr->name
  cout << "Pointer with Arrays " << endl;
  int B[5] = {7,2,0,5,8};

  cout << "B[0] is "  << B[0] << endl;

  int *C = NULL;
  C=B;

  cout << "C[0] is " << C[0] << endl;

  for (int cnt=0; cnt < 5; cnt++)
    cout << B[cnt] << ", ";

  cout << endl;

  for (int cnt=0; cnt < 5; cnt++)
    cout << C[cnt] << ", ";

  cout << endl;

  int N = 8;

  int *PTR = new int[ N ];

  for (int j = 0; j < N ; j++)
  {
   PTR[j]= rand() % 100;
   cout << PTR[j] << ", ";
  }

  cout << "Dynamic 2D array << " << endl << endl << endl;


  int row;
  int col;
  cout << "Enter row and col:" ;
  cin >> row >> col;

  int SA[row][col];  // Check  why it is not giving an error!!!
  SA[0][0] = 3;


  int **D = new int*[row];

 for (int j = 0; j < row ; j++)
  {
      D[j] = new int[col];
  }

  for (int j = 0; j < row ; j++)
  {
      for (int k = 0; k < col ; k++)
        {
          D[j][k] = rand() % 100;
          cout << D[j][k] << ", ";
       }
       cout << endl;
  }
}
