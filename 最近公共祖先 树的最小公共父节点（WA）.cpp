#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node
{
	string name;
	vector<node*> child;
};

int dfs(node* root,const string &a,const string&b, string &ancester) {
	if (root->name == a&&root->name == b) {
		ancester = root->name;
		return 3;
	}
	if (root->child.size() == 0) {
		if (root->name != a&&root->name != b)
			return 0;
		else
			return 1;
	}
	int state = 0;
	for (auto it:root->child){
		state+=dfs(it, a, b, ancester);
	}
	if (root->name == a || root->name == b) {
		if (state==1){
			ancester = root->name;
			return 3;
		}
		return 1;
	}
	if (state==2){
		ancester = root->name;
		return 3;
	}
	return state;
}

int main(void) {
	int n;
	cin >> n;
	map<string,node*> tree;
	vector<node*> root;
	for (int i = 0; i < n;i++) {
		string pa, ch;
		cin >> pa >> ch;
		if (tree.count(pa)==0){
			node* tmp = new node;
			tmp->name = pa;
			root.push_back(tmp);
			tree[pa] = tmp;
		}
		node* ctmp = new node;
		ctmp->name = ch;
		tree[ch] = ctmp;
		tree[pa]->child.push_back(ctmp);
	}
	int checkNum;
	cin >> checkNum;
	for (int i = 0; i < checkNum; i++)
	{
		string a, b,ancester;
		cin >> a >> b;
		for (auto it:root){
			dfs(it, a, b, ancester);
			if (ancester.size()>0){
				cout << ancester << endl;
				break;
			}
		}
		if (ancester.size()==0){
			cout << -1 << endl;
		}
	}
	return 0;
}