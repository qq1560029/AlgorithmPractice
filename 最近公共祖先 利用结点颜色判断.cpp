#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum 
{
	white = 0,gray,black
};

struct node {
	string name;
	vector<node*> child;
	node* parent;
	int color = white;
};

map<string, node*> tree;
vector<pair<string, string>> query;
vector<string> ans;

void dfs(node* root,node* parent) {
	root->color = gray;
	for (int i = 0; i < query.size();i++) {
		if (ans[i].empty()){
			if (root->name==query[i].first){
				if (tree[query[i].second]->color==gray){
					ans[i] = query[i].second;
				}
				else if (tree[query[i].second]->color == black){
					while (tree[query[i].second]->parent->color==black)
						tree[query[i].second]->parent = tree[query[i].second]->parent->parent;
					ans[i] = tree[query[i].second]->parent->name;
				}
				else { //color == white
					swap(query[i].first, query[i].second);
				}
			}
		}
	}
	for (int i = 0; i < root->child.size();i++) {
		//root->child[i]->parent = root;
		dfs(root->child[i],root);
	}
	root->color = black;
	root->parent = parent;
}

int main(void) {
	int n;
	cin >> n;
	string a, b;
	node* root=new node;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (tree.count(a)==0){
			node* tmp = new node;
			tmp->name = a;
			tree[a] = tmp;
		}
		if (tree.count(b) == 0) {
			node* tmp = new node;
			tmp->name = b;
			tree[b] = tmp;
		}
		tree[a]->child.push_back(tree[b]);
		if (i==0){
			root = tree[a];
		}
	}
	cin >> n;
	query.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		query[i]=make_pair(a, b);
	}
	dfs(root,root);
	for (int i = 0; i < n;i++) {
		cout << ans[i] << endl;
	}
	return 0;
}