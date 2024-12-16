#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<std::vector<int>>> SplitBoard(const vector<vector<int>>& matrix)
{
	int size = matrix[0].size() / 2;
	
	vector<vector<vector<int>>> dims(4, vector<vector<int>>(size, vector<int>(size)));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			dims[0][i][j] = matrix[i][j];
			dims[1][i][j] = matrix[i][j + size];
			dims[2][i][j] = matrix[i + size][j];
			dims[3][i][j] = matrix[i + size][j + size];
		}
	}
	
	return dims;
}

int CheckBoard(const vector<vector<int>>& matrix)
{
	int firstVar = matrix[0][0];
	if (matrix[0].size() == 1 and matrix.size() == 1)
	{
		return firstVar;
	}

	int nsize = matrix[0].size();
	for (int i=0; i<nsize; i++)
	{
		for (int j=0; j<nsize; j++)
		{
			if (matrix[i][j] != firstVar)
			{
				return 3;
			}
		}
	}
	return firstVar;
}

void ShowBoard(const vector<vector<int>>& matrix)
{
	for (const auto& row : matrix) 
	{
		for (const auto& value : row)
		{
			cout << value << " ";
		}
		cout << endl;
	}
}

void ShowBoards(const vector<vector<vector<int>>>& matrixs)
{
	for (const auto& matrix : matrixs)
	{
		for (const auto& row : matrix) 
		{	
			for (const auto& value : row)
			{
				cout << value << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int size;
	cin >> size;
	int blueBoard = 0;
	int whiteBoard = 0;
	
	vector<vector<int>> arr(size, vector<int>(size));
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}
	
	vector<vector<vector<int>>> queues;
	queues.push_back(arr);
	while (!queues.empty())
	{
		auto& nxt = queues.back();
		int t = CheckBoard(nxt);
		if (t == 0)
		{
			queues.pop_back();
			whiteBoard++;
		}
		else if (t == 1)
		{
			queues.pop_back();
			blueBoard++;
		}
		else
		{
			auto a = SplitBoard(nxt);
			queues.pop_back();
			for (auto& b : a)
			{
				queues.push_back(b);
			}
		}
		
		//break;
	}
	cout << whiteBoard << "\n" << blueBoard << "\n";
	
	return 0;
}
