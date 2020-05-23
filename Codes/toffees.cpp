#include <bits/stdc++.h>
using namespace std;
int n;
long long ans[1000009], ans2[1000009];
char c;
string s;
vector<pair<int, int> > a;
int main() {
	freopen("toffees.inp", "r", stdin);
	freopen("toffees.out", "w", stdout);
	ans[1] = 10000000;
	cin >> n;
	cin >> s;
	int tmp = 0;
	for (int i = 2; i <= n; i++) {
		c = s[tmp];
		tmp++;
		if (c == '=') ans[i] = ans[i - 1];
		if (c == 'L') ans[i] = ans[i - 1] - 1;
		if (c == 'R') ans[i] = ans[i - 1] + 1;
	}
	a.push_back(make_pair(1, ans[1]));
	for (int i = 2; i <= n; i++) if (ans[i] != a[(int) a.size() - 1].second) a.push_back(make_pair(i, ans[i]));
	vector<int> res;
	for (int i = 1; i < (int) a.size() - 1; i++) if (a[i].second < a[i + 1].second && a[i].second < a[i - 1].second) res.push_back(a[i].first);
	if (a[0] < a[1]) res.push_back(1);
	if (a[a.size() - 1] < a[a.size() - 2]) res.push_back(a[a.size() - 1].first);
	for (int i = 1; i <= n; i++) ans2[i] = 0;
	for (int i = 0; i < res.size(); i++) {
		ans2[res[i]] = 1;
		for (int j = res[i] - 1; j > 0; j--) {
			if (ans[j] > ans[j + 1]) ans2[j] = max(ans2[j + 1] + 1, ans2[j]); 
			else if (ans[j] == ans[j + 1]) ans2[j] = max(ans2[j], ans2[j + 1]);
			else break;
		}
		for (int j = res[i] + 1; j <= n; j++) {
			if (ans2[j]) break;
			if (ans[j] > ans[j - 1]) ans2[j] = max(ans2[j], ans2[j - 1] + 1);
			else if (ans[j] == ans[j - 1]) ans2[j] = max(ans2[j], ans2[j - 1]);
			else break;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans2[i] << " ";
	return 0;
}
