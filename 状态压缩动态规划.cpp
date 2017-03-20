#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countBit(int b) {
	int count=0;
	while (b)
	{
		if (b&1)
			count++;
		b >>= 1;
	}
	return count;
}

int main(void) {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> value(n);
	for (int i = 0; i < n; i++)
	{
		cin>> value[i];
	}
	int maxj = 1 << m;
	vector<int> vtmp(maxj, 0);
	vector<vector<int>> best(2, vtmp);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < maxj; j++)  //状态压缩成用2进制表示 0101：表示选第二个与第四个（往右靠后） 
		{	
			//现在状态j=10b（从左往右表示选了前一次且这次不选） 故前一次j/2=0的最优值为
			//max(j/2,j/2+(1<<(m:2-1))):表示在前一个状态中01b（前一次选，前前一次不选） 11b（前一次和前前一次都选）
			//选出最大的值再加上(j & 1)*value[i]  其中：若j&1==1即状态j=X1b（表示本次选中） 若j&1==0即状态j=X0b（表示本次不选）
			if (countBit(j) <= q)     
				best[i & 1][j] = max(best[~i & 1][j / 2],  
					best[~i & 1][j / 2 + (1 << (m - 1))]) + (j & 1)*value[i];
		}                               //j从0到maxj=1<<m：相当于将j从000···二进制遍历至111···（m-1）位
	}									//j&1：j最后一位是1表明此位要选择
	cout <<	*max_element(best[~n&1].begin(),best[~n&1].end()) << endl;
	return 0;
}