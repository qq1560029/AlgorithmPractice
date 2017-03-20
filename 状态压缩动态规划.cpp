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
		for (int j = 0; j < maxj; j++)  //״̬ѹ������2���Ʊ�ʾ 0101����ʾѡ�ڶ�������ĸ������ҿ��� 
		{	
			//����״̬j=10b���������ұ�ʾѡ��ǰһ������β�ѡ�� ��ǰһ��j/2=0������ֵΪ
			//max(j/2,j/2+(1<<(m:2-1))):��ʾ��ǰһ��״̬��01b��ǰһ��ѡ��ǰǰһ�β�ѡ�� 11b��ǰһ�κ�ǰǰһ�ζ�ѡ��
			//ѡ������ֵ�ټ���(j & 1)*value[i]  ���У���j&1==1��״̬j=X1b����ʾ����ѡ�У� ��j&1==0��״̬j=X0b����ʾ���β�ѡ��
			if (countBit(j) <= q)     
				best[i & 1][j] = max(best[~i & 1][j / 2],  
					best[~i & 1][j / 2 + (1 << (m - 1))]) + (j & 1)*value[i];
		}                               //j��0��maxj=1<<m���൱�ڽ�j��000�����������Ʊ�����111��������m-1��λ
	}									//j&1��j���һλ��1������λҪѡ��
	cout <<	*max_element(best[~n&1].begin(),best[~n&1].end()) << endl;
	return 0;
}