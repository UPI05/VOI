#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1009;
int n, m, s, t, u, v, w, d[NMAX], f[NMAX][NMAX], c[NMAX][NMAX], res = 0;
vector<int> adj[NMAX];
bool bfs(int s, int t) {
	fill(d + 1, d + n + 1, 0);
	d[s] = 1;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i : adj[x]) {
			if (!d[i] && f[x][i] < c[x][i]) {
				d[i] = d[x] + 1;
				q.push(i);
			}
		}
	}	
	return d[t];
}
int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	for (int i : adj[s]) {
		if (d[i] == d[s] + 1 && f[s][i] < c[s][i]) {
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
void cut(int k) {
	d[k] = 1;
	for (int i : adj[k]) {
		if (!d[i] && f[k][i] < c[k][i]) {
			cut(i);
		}
	}	
}
int main() {
	freopen("latcat.inp", "r", stdin);
	freopen("latcat.out", "w", stdout);
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
		while (int ans = dfs(s, t, INT_MAX)) res += ans;
	}	
	fill(d + 1, d + n + 1, 0);
	cut(s);
	vector<int> x, y;
	for (int i = 1; i <= n; i++) {
		if (d[i]) x.push_back(i);
		else y.push_back(i);
	}
	cout << res << endl;
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			if (c[x[i]][y[j]]) {
				cout << x[i] << " " << y[j] << endl;
			}
		}
	}
	return 0;
}
