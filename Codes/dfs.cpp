#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, u, v, c, a[1009][1009], trace[1009];
bool check[1009];
void dfs(int k) {
	check[k] = 1;
	for (int i = 1; i <= n; i++) {
		if (!check[i] && !a[k][i]) {
			trace[i] = k;	
			dfs(i);
		}
	}
}
int main() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		check[i] = 0;
		trace[i] = 0;
		for (int j = 1; j <= m; j++) a[i][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> c;
		a[u][v] = c;
	}
	dfs(s);	

	return 0;
}
