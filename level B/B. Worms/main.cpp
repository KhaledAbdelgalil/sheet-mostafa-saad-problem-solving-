#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;


int main()
{


	int i,n;
	int m, q;
	int first;
	cin >> n;

	int* number = new int[n + 1];

	number[0] = 0;
	for (i = 0; i<n; i++) {

		cin >> first;
		number[i + 1] = number[i] + first;
	}



	cin >> m;

	for (i = 0; i < m; i++)
	{
		cin >> q;
		int ans = lower_bound(number, number+n+1, q)-number;
		cout << ans << endl;
	}



	return 0;
}
