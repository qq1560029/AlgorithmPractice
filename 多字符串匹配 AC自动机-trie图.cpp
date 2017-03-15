#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <memory>

using namespace std;

struct tnode {
	char name;
	int count = 0;
	int color = 0;
	unordered_map<char, shared_ptr<tnode>> child;
	shared_ptr<tnode> prev;   // ß–ß÷∏’Î
};

void trieCreat(shared_ptr<tnode> head, string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (head->child.count(s[i]) != 0) {
			head->count++;
			head = head->child[s[i]];
		}
		else {
			shared_ptr<tnode> chd = make_shared<tnode>();
			chd->name = s[i];
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

void buildTrie(shared_ptr<tnode> head) {
	deque<shared_ptr<tnode>> Q;
	for (char i = 'a'; i <= 'z'; i++){
		if (head->child.count(i) != 0) {
			head->child[i]->prev = head;
			Q.push_back(head->child[i]);
		}
	}
	while (!Q.empty()){
		shared_ptr<tnode> u = Q.front();
		Q.pop_front();
		for (char i = 'a'; i <= 'z'; i++) {
			if (u->child.count(i) != 0) {
				shared_ptr<tnode> pre = u->prev;
				while (pre!=NULL){
					if (pre->child.count(i) != 0) {
						u->child[i]->prev = pre->child[i];
						if (u->child[i]->prev->color != 0)
							u->color++;
						break;
					}
					else
						pre = pre->prev;
				}
				if (u->child[i]->prev==NULL)
					u->child[i]->prev = head;
				Q.push_back(u->child[i]);
			}
		}
	}
}

bool search(shared_ptr<tnode> root, string &str) {
	auto head = root;
	for (int i = 0; i < str.size(); i++)
	{
		while (true)
		{
			if (head->child.count(str[i])!=0){
				head = head->child[str[i]];
				if (head->color != 0)
					return true;
				break;
			}
			else 
				head = head->prev;
			if (head==root||head==NULL){
				head = root;
				break;
			}
		}
	}
	return false;
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
	buildTrie(head);
	string str;
	cin >> str;
	search(head, str) == true ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}