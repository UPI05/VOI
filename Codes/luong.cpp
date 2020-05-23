#include <bits/stdc++.h>
using namespace std;
int n, m, tr[1009], u, v, c, d[1009][1009];
bool check[1009], ok = 0;
void dfs(int k) {
	if (k == n) ok = 1;
	check[k] = 1;
	for (int i = 1; i <= n; i++) {
		if (!check[i] && d[k][i]) {
			tr[i] = k;
			dfs(i);
		}
	}
}
int main() {
	freopen("a.inp", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> c;
		d[u][v] = c;
	}
	for (int i = 1; i <= n; i++) {
		check[i] = 0;
		tr[i] = 0;
	}
	dfs(1);
	int res = 0;
	while (ok) {
		int deltaF = 1000000009;	
		int t = n;
		while (tr[t] != 1) {
			deltaF = min(deltaF, d[tr[t]][t]);
			d[tr[t]][t] -= deltaF;
			d[t][tr[t]] += deltaF;
			t = tr[t];
		}
		res += deltaF;
		ok = 0;
		for (int i = 1; i <= n; i++) {
			check[i] = 0;
			tr[i] = 0;
		}
		dfs(1);	
	}
	cout << res;
	return 0;
}
