#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	std::string fb[3];
	int nnum=0;
	std::string ans = "";
	
	cin >> fb[0];
	cin >> fb[1];
	cin >> fb[2];
	
	for (int i=0; i<3; i++)
	{
		if (isdigit(char(fb[i][0])))
		{
			nnum = std::stoi(fb[i]) + (3 - i);
			break;
		}
	}
	
	if (nnum % 3 == 0) {
		ans = "Fizz";
	} 
	if (nnum % 5 == 0)
	{
		ans += "Buzz";
	}
	
	if (ans == "")
	{
		cout << nnum;
	}
	else
	{
		cout << ans;
	}
	return 0;
}

