#include <iostream>
#include <cstdlib>

using namespace std;

struct car {
	int price;
	unsigned short year;
};

const int Cap = 10;
car S[Cap];
int count=0;

void add();
void list();

int main() {
	for (int i=0; i < 5 ; i++)  add();

	list();
	
}

void list() { //  prints all items of the bag
	for (int i=0; i < count; i++)
		cout << S[i].price << ", " << S[i].year << endl;
	cout << endl;
}

	void add() {
		if (count < Cap ) {
			S[count].price= 5000 + rand() % 5001;
			S[count++].year=  2000 + rand() % 20;
		}

	}

