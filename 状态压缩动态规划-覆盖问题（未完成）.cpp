#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int maxs = (1 << m << m);  //��2mλ״̬ ǰmλ��¼��һ�е���Ϣ����mλ��¼��һ�е���Ϣ ״̬Ϊ1��ʾ��λ��ռ
	int maxrow = (1 << m) - 1;
	int cur = 1;
	vector<int> vtmp(maxs, 0);
	vector<vector<int>> sum(2, vtmp);//ֻ���¼Ŀǰ�к�ǰһ�У�����ǰ�Ķ��Ѿ���ȫ����
	sum[0][0] = 1;
	for (int i = 0; i < n; i++) {
		cur ^= 1;  //���м��л�
		for (int j = 0; j < m; j++){  //�ŵ�i��j��
			for (int s= 0; s < maxs; s++) {
				if ((s&(1 << j)) == 0) {  //j��û�з�����һ�е�j��Ҳһ��û�з�
					sum[cur][s | (1 << j) | (1 << (j + m))]
						= (sum[cur][s | (1 << j) | (1 << (j + m))] + sum[cur][s]) % MOD; //����
					if ((j + 1) < m && ((s&(1 << (j + 1))) == 0)) { //jû����j+1û��
						sum[cur][s | (1 << j) | (1 << (j + 1))]
							= (sum[cur][s | (1 << j) | (1 << (j + 1))] + sum[cur][s]) % MOD; //���
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