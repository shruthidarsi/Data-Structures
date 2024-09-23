// MMete
// How to model salespeople with quarter sales and total of them
// Jan 22, 2019

#include <iostream>
#define  N 6
using namespace std;

double GTotal = 0;
double GQS[4]={0};

struct SP {
    string name;
    double QS[4];
    double total;
};

SP MyCom[N];

int main()
{

 srand(123); // srand(time());
 cout << "You have " << N << " salespeople with:" << endl;
 cout << "ID \t Name \t QS1 \t QS2 \t QS3 \t QS4 \t Total" << endl;

 double sum = 0;
 for (int cnt = 0; cnt < N; cnt++)
 {
     MyCom[cnt].name = "Amy";
     cout << 101 + cnt << " \t "  << MyCom[cnt].name << "\t"  ;

     for (int k=0; k < 4; k++) // For each salesperson
     {
        MyCom[cnt].QS[k] = rand() % 1000;
        sum = sum + MyCom[cnt].QS[k];
        cout <<  MyCom[cnt].QS[k] << "\t";
     }
     MyCom[cnt].total = sum;
     GTotal  = GTotal + MyCom[cnt].total;
     cout <<  MyCom[cnt].total <<endl;
 }
   for (int k=0; k < 4; k++)
   {
    sum = 0;
    for (int cnt = 0; cnt < N; cnt++)
    {
     sum = sum + MyCom[cnt].QS[k];
    }

    GQS[k] = sum;
  }

  cout << "Total \t   \t" << GQS[0] << " \t" << GQS[1] << " \t" << GQS[2] << " \t" << GQS[3] << "\t" << GTotal <<endl;


}
