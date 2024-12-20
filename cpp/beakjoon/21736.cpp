#include <iostream>
#include <vector>
using namespace std;

void showMatrix(const vector<vector<char>>& matrix)
{
	for (auto& row : matrix)
	{
		for (auto& elem : row)
		{
			cout << elem;
		}
		cout << "\n";
	}
	
	cout << "\n\n";
}

int moveMatrix(vector<vector<char>>& matrix, int row, int col)
{
	// cout << "ROW : " << row << ",Col :" << col << "\n";
	
	if (matrix[row][col] == 'X')
	{
		return 0;
	}

	// showMatrix(matrix);
	if (matrix[row][col] == 'P')
	{
		matrix[row][col] = 'X';
		return 1 + moveMatrix(matrix, row + 1, col) + moveMatrix(matrix, row - 1, col) + moveMatrix(matrix, row, col + 1) + moveMatrix(matrix, row, col - 1);
	}
	matrix[row][col] = 'X';
	return 0 + moveMatrix(matrix, row + 1, col) + moveMatrix(matrix, row - 1, col) + moveMatrix(matrix, row, col + 1) + moveMatrix(matrix, row, col - 1);
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	

	int row, col;
	cin >> row >> col;

	vector<vector<char>> matrix(row + 2, vector<char>(col + 2));


	for (int i = 0; i < row + 2; i++)
	{
		if (i == 0 || i == row + 1)
		{
			for (int j = 0; j < col + 2; j++)
			{
				matrix[i][j] = 'X';
			}
			continue;
		}
		
		matrix[i][0] = 'X';
		matrix[i][col + 1] = 'X';
		for (int j = 1; j < col + 1; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int sRow=0;
	int sCol=0;
	
	for (int i=1; i<row+1;i++)
	{
		for (int j=1;j<col+1;j++)
		{
			if (matrix[i][j] == 'I')
			{
				sRow = i;
				sCol = j;
				break;
			}
		}
		if (sRow != 0)
		{
			break;
		}
	}
	// cout << sRow << sCol << "\n";
	int t = moveMatrix(matrix, sRow ,sCol);
	if (t == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << t;
	}

	
	return 0;
}
