#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct tnode {
	char name;
	int count = 0;
	int color = 0;
	unordered_map<char, tnode*> child;
};

void trieCreat(tnode* ohead, string &s) {
	tnode* head = ohead;
	for (int i = 0; i < s.size(); i++) {
		if (head->child.count(s[i]) != 0) {
			head->count++;
			head = head->child[s[i]];
		}
		else {
			tnode *chd = new tnode;
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


int getTrieNum(tnode *head, string &s) {
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
	tnode head;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trieCreat(&head, s);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout << getTrieNum(&head, s) << endl;
	}
	return 0;
}