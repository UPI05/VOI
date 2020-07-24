#include <bits/stdc++.h>
using namespace std;
int n;
string s, res = "";
bool check[30];
int main() {
	freopen("twoc.inp", "r", stdin);
	freopen("twoc.out", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i <= 30; i++) check[i] = 0;
	for (int i = 0; i < s.length(); i++) check[s[i] - 'a'] = 1;
	for (int i = 0; i < 30; i++) {
		for (int j = i + 1; j <= 30; j++) {
			string t = "";
			for (int k = 0; k < s.length(); k++) if (s[k] - 'a' == i || s[k] - 'a' == j) t += s[k];
			bool ok = true;
			for (int k = 1; k < t.length(); k++) {
				if (t[k] == t[k - 1]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				if (t.size() > res.size()) res = t;
			}
		}
	}
	cout << res.size();
	return 0;
}
