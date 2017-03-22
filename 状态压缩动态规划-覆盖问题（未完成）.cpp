#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int maxs = (1 << m << m);  //共2m位状态 前m位记录这一行的信息，后m位记录下一行的信息 状态为1表示此位已占
	int maxrow = (1 << m) - 1;
	int cur = 1;
	vector<int> vtmp(maxs, 0);
	vector<vector<int>> sum(2, vtmp);//只需记录目前行和前一行，再以前的都已经完全填满
	sum[0][0] = 1;
	for (int i = 0; i < n; i++) {
		cur ^= 1;  //两行间切换
		for (int j = 0; j < m; j++){  //放第i行j列
			for (int s= 0; s < maxs; s++) {
				if ((s&(1 << j)) == 0) {  //j处没有放则下一行的j处也一定没有放
					sum[cur][s | (1 << j) | (1 << (j + m))]
						= (sum[cur][s | (1 << j) | (1 << (j + m))] + sum[cur][s]) % MOD; //竖放
					if ((j + 1) < m && ((s&(1 << (j + 1))) == 0)) { //j没放且j+1没放
						sum[cur][s | (1 << j) | (1 << (j + 1))]
							= (sum[cur][s | (1 << j) | (1 << (j + 1))] + sum[cur][s]) % MOD; //横放
					}
				}
			}
		}
		for (int s = 0; s < maxs;s++) {
			if ((s&maxrow)==maxrow){
				sum[cur ^ 1][s >> m] = sum[cur][s];
			}
		}
	}
	cout << sum[1][maxrow] << endl;
	return 0;
}