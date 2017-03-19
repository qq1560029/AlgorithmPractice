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
	for (int i = 0; i < n;i++) {
		for (int j = need[i]; j<coin; j++)   //在只选前i种商品时 花j这么多钱能获得的最大收益  顺序遍历，故每种商品i可选多次
		{
			table[j] = max(table[j], table[j - need[i]] + value[i]);
		}
	}
	cout << table[coin-1] << endl;
	return 0;
}