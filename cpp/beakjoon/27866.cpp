#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 

	string a;
	cin >> a;
	int b;
	cin >> b;
	cout << a[b-1];
	
	return 0;
}
