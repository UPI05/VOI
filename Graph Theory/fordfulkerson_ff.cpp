#include <bits/stdc++.h>
using namespace std;
int m, res = 0, c, adj[30][30], tr[30];
bool check[30];
char u, v;
void dfs(int k) {
	check[k] = 1;
	for (int i = 0; i <= (int) ('T' - 'A'); i++) {
		if (i > (int) ('O' - 'A') && i < (int) ('T' - 'A')) continue;
		if (adj[k][i] && !check[i]) {
			tr[i] = k;
			dfs(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen("ff.inp", "r", stdin);
	//freopen("ff.out", "w", stdout);
	for (int i = 0; i <= (int) ('T' - 'A'); i++) {
		for (int j = 0; j <= (int) ('T' - 'A'); j++) {
			adj[i][j] = 0;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> c;
		adj[u - 'A'][v - 'A'] = c;
	}
	for (int i = 0; i <= (int) ('T' - 'A'); i++) {
		tr[i] = -1;
		check[i] = 0;
	}
	dfs((int) ('S' - 'A'));
	while (check[(int) ('T' - 'A')]) {
		int t = 'T' - 'A';
		int Min = 1000000009;
		while (tr[t] != -1) {
			Min = min(adj[tr[t]][t], Min);
			t = tr[t];
		}
		t = 'T' - 'A';
		while (tr[t] != -1) {
			adj[tr[t]][t] -= Min;
			adj[t][tr[t]] += Min;
			t = tr[t];
		}
		res += Min;
		for (int i = 0; i <= (int) ('T' - 'A'); i++) {
			tr[i] = -1;
			check[i] = 0;
		}
		dfs((int) ('S' - 'A'));
	}
	cout << res;	
	return 0;
}
