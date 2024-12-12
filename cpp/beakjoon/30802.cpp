#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int total;
	int s,m,l,xl,xxl,xxxl;
	int t, p;
	
	cin >> total;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	cin >> t >> p;
	
	int q = 0;
	q += s / t;
	if (s % t != 0)
	{
		q += 1;
	}
	
	q += m / t;
	if (m % t != 0)
	{
		q += 1;
	}
	
	q += l / t;
	if (l % t != 0)
	{
		q += 1;
	}
	
	q += xl / t;
	if (xl % t != 0)
	{
		q += 1;
	}
	
	q += xxl / t;
	if (xxl % t != 0)
	{
		q += 1;
	}
	
	q += xxxl / t;
	if (xxxl % t != 0)
	{
		q += 1;
	}	
	
	cout << q << "\n";
	cout << (total / p) << " " << (total % p);
	
	return 0;
}
