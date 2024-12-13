#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int cnt;
	int* arr;
	float percent = (15.0/100);
	int excp = 0;

	
	cin >> cnt;
	
	if (cnt == 0)
	{
		cout << 0;
		return 0;
	}
	
	excp = round(cnt * percent);
	
	arr = new int[cnt];
	
	for (int i=0; i<cnt; i++)
	{
		cin >> arr[i];
	}
	vector<int> sortedArr;
	
	
	sortedArr.assign(arr, arr+cnt);
	sort(sortedArr.begin(), sortedArr.end());
	
	float sum = 0;
	for (int i= excp; i < cnt - excp; i++)
	{
		sum += sortedArr[i];
	}
	
	int remainingCount = cnt - excp * 2;
	cout << round(sum / remainingCount);
	
	delete[] arr;
	
	return 0;
}