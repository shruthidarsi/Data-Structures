#include <iostream>
#include <math.h>

using namespace std;

struct SP
{
	unsigned int ID;
	float sales[4];
	float total;
};

SP Company[6];

int main()
{
	for (int i = 0; i < 6; i++)
	{
		Company[i].ID = 500 + (rand() % 49501); // ID selection for 500...50000
												// float cur_total = 0;
		Company[i].total = 0;
		for (int j = 0; j < 4; j++)
		{
			Company[i].sales[j] = rand() % 1000;
			// cur_total = cur_total + Company[i].sales[j];
			Company[i].total = Company[i].total + Company[i].sales[j];
		}
		//Company[i].total = cur_total;
	}

	for (int i = 0; i < 6; i++)
	{
		cout << Company[i].ID << endl;
	}


	system("pause");
}