#include <iostream>
#include <vector>
#include <deque>
//#include "matrix.hpp"
using namespace std;

struct Pos
{
	int row;
	int col;
	int temp = 0;
};

struct Block
{
	bool isVisited = true;
	int value = -1;
	int priority = 0;
};

struct Board
{
	vector<vector<Block>> blocks;
	int rows;
	int cols;

	Board(int r, int c) : rows(r + 2), cols(c + 2), blocks(r + 2, vector<Block>(c + 2)){};


	Block& getBlock(int r, int c) {
		return blocks[r][c];
	}
	
	vector<vector<int>> getPriority() {
		vector<vector<int>> matrix(rows - 2, vector<int>(cols - 2));
		for (int i = 1; i < rows-1; ++i) {
			for (int j = 1; j < cols-1; ++j) {
				if (blocks[i][j].isVisited)
				{
					matrix[i-1][j-1] = blocks[i][j].priority;
				}
				else
				{
					if (blocks[i][j].value > 0)
					{
						matrix[i-1][j-1] = -1;
					}
					else
					{
						matrix[i-1][j-1] = 0;
					}
				}
			}
		}
		return matrix;
	}
};

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int row, col;
	
	cin >> row >> col;
	
	Board board(row, col);
	int startRow;
	int startCol;
	
	deque<Pos> poses;
	
	for (int i=1; i<row+1; i++)
	{
		for (int j=1; j<col+1; j++)
		{
			cin >> board.getBlock(i, j).value;

			board.getBlock(i, j).isVisited = false;
			if (board.getBlock(i, j).value == 2)
			{
				startRow = i;
				startCol = j;
				poses.push_back({startRow, startCol});
			}
		}
	}
	
	do
	{
		auto pos = poses.back();
		poses.pop_back();
		Block& block = board.getBlock(pos.row, pos.col);
		if (!block.isVisited)
		{
			block.isVisited = true;
			if (block.value > 0)
			{
				block.priority = pos.temp;
				poses.push_front({pos.row + 1, pos.col, block.priority + 1});
				poses.push_front({pos.row, pos.col + 1, block.priority + 1});
				poses.push_front({pos.row - 1, pos.col, block.priority + 1});
				poses.push_front({pos.row, pos.col - 1, block.priority + 1});
			}

		}
	}
	while (poses.size() > 0);
	
	auto ans = board.getPriority();
	for (auto& row : ans)
	{
		for (auto& col : row)
		{
			cout << col << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
