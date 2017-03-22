#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node
{
	int name;
	vector<node*> child;
};

int main(void) {
	int n,m;
	cin >> n >> m;    //n中选m个连通的结点  求出连通结点对于value的和的最大值
	vector<int> value(n);
	for (int i = 0; i < n;i++)
		cin >> value[i];
	vector<node*> tree(n);
	for (int i = 0; i < n;i++) {
		node* tmp = new node;
		tmp->name = i;
		tree[i]=tmp;
	}
	int root;
	for (int i = 0; i < n-1;i++) {
		int a, b;
		cin >> a >> b;
		if (i==0){
			root = a-1;
		}
		tree[a-1]->child.push_back(tree[b-1]);
	}
	vector<int> tdp(m+1, 0);  //0 1 2 ... m
	vector<vector<int>> dp(n, tdp);
	for (int i = 0; i < n; i++)
		dp[i][1] = value[i];
	stack<node*> stack;
	stack.push(tree[root]);
	node* last=tree[root];
	node* t = tree[root];
	while (!stack.empty()){  //后序遍历树 找到每个结点选取0 1 ... m个连通结点时的最大value  dp[i][mn]
		t = stack.top();
		if (t->child.empty()||last==t->child.back())
		{
			for (auto chd:t->child) {  //遍历各个子节点
				for (int mn= m; mn > 1;mn--) {  //每个子节点各取多少个结点 最终此根节点能获得最大值
					for (int mcn = 1; mcn < mn;mcn++) {
						dp[t->name][mn] = max(dp[t->name][mn], dp[t->name][mcn] + dp[chd->name][mn - mcn]);
					}
				}
			}
			//cout << t->name<<" "<<dp[t->name][m]<<endl;
			last = t;
			stack.pop();
		}
		else {
			for (int i = t->child.size() - 1; i >= 0;i--) {
				stack.push(t->child[i]);
			}
		}
	}
	int maxval = 0;
	for (int i = 0; i < tree.size();i++) {   //遍历每个根节点 找到具有最大值的那一个
		if (dp[i][m]>maxval){
			maxval = dp[i][m];
		}
	}
	cout << maxval << endl;
	return 0;
}