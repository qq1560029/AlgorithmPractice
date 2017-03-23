#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	string name;
	node* next;
};

node* fin(node* first) {  //找到并查集的最终指向结点
	while (first!=first->next)
	{
		first = first->next;
	}
	return first;
}

int main(void) {
	int n,op;
	cin >> n;
	string a, b;
	map<string, node*> data;
	for (int i = 0; i < n; i++) {
		cin >> op >> a >> b;
		if (op == 0) {  //维护并查集  合并集合只需使指向的结点一致即可
			if (data.count(a) == 0&&data.count(b)==0) {
				node* tmpa = new node;
				tmpa->name = a;
				tmpa->next = tmpa;
				data[a] = tmpa;
				node* tmpb = new node;
				tmpb->name = b;
				tmpb->next = data[a];
				data[b] = tmpb;
			}
			else if (data.count(a) == 0 && data.count(b) != 0) {
				node* tmpa = new node;
				tmpa->name = a;
				data[a] = tmpa;
				data[b]->next = fin(data[b]);
				data[a]->next = data[b]->next;
			}
			else if (data.count(a) != 0 && data.count(b) == 0){
				node* tmpb = new node;
				tmpb->name = b;
				data[b] = tmpb;
				data[a]->next = fin(data[a]);
				data[b]->next = data[a]->next;
			}
			else
			{
				fin(data[b])->next=fin(data[a])->next;
			}
		}
		else if(op==1)
		{
			if (data.count(a) == 0 || data.count(b) == 0) 
				cout << "no" << endl;
			else if (fin(data[a]) == fin(data[b])) 
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}