#include <bits/stdc++.h>
using namespace std;
int pos = 0;
string res = "", s, t;
int inc() {
        if (pos == s.length() - 1) pos = 0;
	else pos++;
	return pos;
}	
int main() {
	freopen("subrep.inp", "r", stdin);
	freopen("subrep.out", "w", stdout);
	cin >> s >> t;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == s[pos]) {
			res += t[i];
			inc();
		}
	}
	cout << res.length() / s.length();
	return 0;
}
