#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct tnode {
	char name;
	int count = 0;
	int color = 0;
	vector<tnode*> child;
};

void trieCreat(tnode* ohead,string &s) {
	tnode* head = ohead;
	for (int i=0;i<s.size();i++)
	{
		int childExist=0;
		for (int j=0;j<(head->child.size());j++)
		{
			if (s[i]==head->child[j]->name)
			{		
				head->count++;
				head = head->child[j];
				childExist = 1;
				break;
			}
		}
		if (childExist==0)
		{
			tnode *chd = new tnode;
			chd->name = s[i];
			//chd->count = 1;
			head->child.push_back(chd);
			head->count++;
			head = head->child[head->child.size()-1];
		}
		if (i==s.size()-1)
		{
			head->color++;
		}
	}
}

int getTrieNum(tnode *head, string &s) {
	for (int i=0;i<s.size();i++)
	{
		int childExist = 0;
		for (int j = 0; j < (head->child.size()); j++)
		{
			if (s[i] == head->child[j]->name)
			{
				childExist = 1;
				head = head->child[j];
				break;
			}
		}
		if (childExist==0)
		{
			return 0;
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
		cout << getTrieNum(&head, s)<<endl;
	}
	return 0;
}