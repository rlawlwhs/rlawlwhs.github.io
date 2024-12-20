#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void showTanghuru(vector<int>& tanghuru)
{
	for (auto& fruit : tanghuru)
	{
		cout << fruit;
	}
	
	cout << "\n";
}

bool isFruitIn(vector<int>& fruitType, int target)
{
	if (fruitType[0] == target || fruitType[1] == target)
	{
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int len;
	cin >> len;
	
	vector<int> tanghuru(len + 2);
	vector<int> fruitType(2);
	
	vector<int> newtanghuru;
	
	tanghuru[0] = 0;
	tanghuru[tanghuru.size() - 1] = 0;
	
	int maxSize = 0;
	
	for (int i=1; i<len+1; i++)
	{
		cin >> tanghuru[i];
	}
	
	
	int *fptr = &tanghuru[0];
	int *sptr = &tanghuru[0];
	
	do
	{
		sptr++;
		if (*fptr != *sptr)
		{
			fruitType[0] = *fptr;
			fruitType[1] = *sptr;
			
			
			while (fptr != &tanghuru[0] && isFruitIn(fruitType,  *(fptr-1)))
			{
				//cout << "move left\n";
				fptr--;
			}
			
			while (sptr != &tanghuru[tanghuru.size() - 1] && isFruitIn(fruitType,  *(sptr+1)))
			{
				//cout << "move right\n";
				sptr++;
			}
			
			do
			{
				if (*fptr != 0)
				{
					newtanghuru.push_back(*fptr);
				}
				fptr++;
			}
			while (fptr !=  (sptr+1));
			
			
			//showTanghuru(newtanghuru);
			
			if (maxSize < newtanghuru.size())
			{
				maxSize = newtanghuru.size();
			}
				
			//cout << maxSize << "\n";
		}
		
		fptr = sptr;
		
		newtanghuru.clear();
	}
	while (sptr != &tanghuru[tanghuru.size() -1]);
	
	cout << maxSize;
	
	return 0;
}
