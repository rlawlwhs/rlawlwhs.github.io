#include <iostream>
#include <vector>
#include "matrix.hpp"
using namespace std;


int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int row, col;
	
	cin >> row >> col;
	
	vector<vector<int>> matrix(row, vector<int>(col));
	
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	showMatrix(matrix);

	return 0;
}
