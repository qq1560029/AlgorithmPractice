#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, coin;
	cin >> n >> coin;
	vector<int> need(n);
	vector<int> value(n);
	for (int i = 0; i < n; i++)
	{
		cin>> need[i] >> value[i];
	}
	vector<int> table(coin, 0);
	table[need[0]] = value[0];
	for (int i = 1; i < n;i++) {
		for (int j = coin-1; j  >= need[i]; j--)
		{
			table[j] = max(table[j], table[j - need[i]] + value[i]);
		}
	}
	cout << *max_element(table.begin(), table.end()) << endl;
	return 0;
}