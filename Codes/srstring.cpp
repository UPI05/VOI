#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> a, b;
int main() {
	freopen("srstring.inp", "r", stdin);
	freopen("srstring.out", "w", stdout);
	cin >> s;
	a.push(s[0]);
	for (int i = (int) s.length() - 1; i > 0; i--) b.push(s[i]);
	while (b.size()) {
		int t = b.top();
		b.pop();
		if (a.size()) {
			if (a.top() == t) {
				a.pop();
			} else {
				a.push(t);
			}
		} else {
			a.push(t);
		}
	}
	string st = "";
	while (a.size()) {
		st = a.top() + st;
		a.pop();
	}
	st != "" ? cout << st : cout << "Empty String";
	return 0;
}
