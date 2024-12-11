#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	string a;
	string b;
	string c;
	
	cin >> a;
	cin >> b;
	cin >> c;
	
	cout << (stoi(a) + stoi(b) - stoi(c)) << "\n";
	cout << (stoi(a + b) - stoi(c)) << "\n";
	
	
	return 0;
}
