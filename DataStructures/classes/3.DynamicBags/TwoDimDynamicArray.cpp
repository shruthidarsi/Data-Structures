#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
	unsigned short rDim= 1, cDim=1;
	while (rDim > 0 && cDim >0) {

		cout << "Enter sizes of 2D array: <row> <col>:";
		cin >> rDim >> cDim;

		// int *board[rDim];
		int **board = new int* [rDim];

		for (int row=0; row< rDim ; row++)
			board[row] = new int[cDim];

		for (int row=0; row< rDim ; row++) {
			for (int col=0; col< cDim ; col++) {
				board[row][col] = rand() % 100;
				//cout << setw(5) << board[row][col];
			}
			cout << endl;
		}
		
		for (int row=0; row< rDim ; row++)		
			delete [] board[row];
			
			delete [] board;
		
	}
}
