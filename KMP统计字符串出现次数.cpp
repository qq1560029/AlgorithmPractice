#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getNext(string &s) {
	int len = s.size();
	vector<int> next(len+1, 0); //next数组从1开始
	int j = 0;
	for (int i=1;i<len;i++)
	{
		while (j > 0 && s[i] != s[j])
			j = next[j];
		if (s[i] == s[j])
			j++;
		next[i + 1] = j;
	}
	return next;
}

void kmp(string &ori, string &par) {
	auto next = getNext(par);
	int count = 0;
	int j = 0;
	for (int i = 0; i < ori.size(); i++)
	{
		while (j > 0 && ori[i] != par[j])
			j = next[j];
		if (ori[i]==par[j])
			j++;
		if (j==par.length())
		{
			count++;
			j = next[j];
		}
	}
	cout << count << endl;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string ori,par;
		cin >> par >> ori;
		kmp(ori, par);
	}
	return 0;
}