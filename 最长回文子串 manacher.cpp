#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void pmax(string &s) {
	int len = s.size();
	string ss;
	ss += '#';
	for (int i = 0; i < len; i++) {
		ss += s[i];
		ss += '#';
	}
	int maxlen = 0;
	len = ss.size();
	vector<int> RL(len, 0);
	int maxright = 0;
	int pos = 0;
	for (int i = 0; i < len; i++) {
		if (i < maxright)
			RL[i] = min(RL[2 * pos - i], maxright - i);
		else
			RL[i] = 1;
		while (i - RL[i] >= 0 && i + RL[i] < len&&ss[i - RL[i]] == ss[i + RL[i]])
			RL[i]++;
		if (RL[i] + i - 1 > maxright) {
			maxright = RL[i] + i - 1;
			pos = i;
		}
		maxlen = max(maxlen, RL[i]);
	}
	cout << maxlen - 1 << endl;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pmax(s);
	}
	return 0;
}