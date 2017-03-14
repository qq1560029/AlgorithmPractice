#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <memory>

using namespace std;

struct tnode {
	char name;
	int count = 0;
	int color = 0;
	unordered_map<char, shared_ptr<tnode>> child;
};

void trieCreat(shared_ptr<tnode> head, string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (head->child.count(s[i]) != 0) {
			head->count++;
			head = head->child[s[i]];
		}
		else {
			shared_ptr<tnode> chd = make_shared<tnode>();
			//tnode *chd = new tnode;
			chd->name = s[i];
			//chd->count = 1;
			head->child[s[i]] = chd;
			head->count++;
			head = head->child[s[i]];
		}
		if (i == s.size() - 1)
		{
			head->color++;
		}
	}
}


int getTrieNum(shared_ptr<tnode> head, string &s) {
	for (int i = 0; i < s.size(); i++)
	{
		if (head->child.count(s[i])==0){
			return 0;
		}
		else{
			head = head->child[s[i]];
		}
	}
	return head->count + head->color;
}

int main(void) {
	int n;
	cin >> n;
	shared_ptr<tnode> head = make_shared<tnode>();
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trieCreat(head, s);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout << getTrieNum(head, s) << endl;
	}
	return 0;
}