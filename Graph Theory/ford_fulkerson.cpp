#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, res = 0, u, v, w, adj[109][109], tr[109];
bool check[109];
void bfs(int k) {
	queue<int> q;
	q.push(k);
	check[k] = 1;
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (adj[t][i] && !check[i]) {
				q.push(i);
				check[i] = 1;
				tr[i] = t;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) adj[i][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u][v] = w;
	}
	for (int i = 1; i <= n; i++) tr[i] = -1, check[i] = 0;
	bfs(s);
	while (check[t]) {
		int delta = INT_MAX;
		int tmp = t;
		while (tr[tmp] != -1) {
			delta = min(delta, adj[tr[tmp]][tmp]);
			tmp = tr[tmp];
		}	
		res += delta;
		tmp = t;
		while (tr[tmp] != -1) {
			adj[tmp][tr[tmp]] += delta;
			adj[tr[tmp]][tmp] -= delta;
			tmp = tr[tmp];
		}
		for (int i = 1; i <= n; i++) tr[i] = -1, check[i] = 0;
		bfs(s);	
	}
	cout << res;
	return 0;
}
