#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

struct node
{
	int name;
	vector<node*> child;
	int first = 0;
	int second = 0;
};

int main(void) {
	int n;
	cin >> n;
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
	stack<node*> stack;
	stack.push(tree[root]);
	node* last=tree[root];
	node* t = tree[root];
	while (!stack.empty()){  //后序遍历树  维护每个结点最长路径长度first与不重复的次长路径长度second，最终树内first+second最大的结点是拐点，最长路径值是拐点的first+second 
		t = stack.top();
		if (t->child.empty()||last==t->child.back())
		{
			if (t->child.size()==1){
				t->first=t->child[0]->first+1;
				t->second = 0;
			}
			else if(t->child.size()>1)
			{
				for (auto it:t->child){
					if (it->first>t->second){
						if (it->first>t->first){
							t->second = t->first;
							t->first = it->first;
						}
						else{
							t->second = it->first;
						}
					}
				}
				t->first++;
				t->second++;
			}
			//cout << t->name<<" "<<t->first<<" "<<t->second<<endl;
			last = t;
			stack.pop();
		}
		else {
			for (int i = t->child.size() - 1; i >= 0;i--) {
				stack.push(t->child[i]);
			}
		}
	}
	int maxlen = 0;
	for (int i = 0; i < tree.size();i++) {
		if ((tree[i]->first+tree[i]->second)>maxlen){
			maxlen = tree[i]->first + tree[i]->second;
		}
	}
	cout << maxlen << endl;
	return 0;
}