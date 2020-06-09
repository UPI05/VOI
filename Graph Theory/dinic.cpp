#include <bits/stdc++.h>
const int NMAX = 1009;
using namespace std;
vector<int> adj[NMAX];
int n, m, s, t, u, v, f[NMAX][NMAX], c[NMAX][NMAX], w, res = 0, d[NMAX];
bool bfs(int s, int t) {
	fill(d + 1, d + n + 1, 0);
	queue<int> q;
	d[s] = 1;
	// Nerver let d[s] be 0.
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i : adj[x]) {
			if (!d[i] && f[x][i] < c[x][i]) {
				q.push(i);
				d[i] = d[x] + 1;
			}
		}

	}
	return d[t];
}
int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	for (int i : adj[s]) {
		if ((d[i] == d[s] + 1) && f[s][i] < c[s][i]) {
			int delta = dfs(i, t, min(flow, c[s][i] - f[s][i]));	
			if (delta > 0) {
				f[s][i] += delta;
				f[i][s] -= delta;
				return delta;
			}

		}
	}
	return 0;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = w; c[v][u] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = 0;
		}
	}
	while (bfs(s, t)) {
		while (int ans = dfs(s, t, 100000000)) res += ans;	
	}
	cout << res;
	return 0;
}
