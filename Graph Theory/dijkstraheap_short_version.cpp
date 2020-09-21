#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, m, u, v, w, d[10009];
vector<ii> adj[10009];
priority_queue<ii, vector<ii>, greater<ii> > pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(ii(w, v));
		adj[v].push_back(ii(w, u));
	}
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	d[1] = 0;
	pq.push(ii(0, 1));	
	while (pq.size()) {
		u = pq.top().second;
		long long du = pq.top().first;
		pq.pop();
		if (du != d[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			v = adj[u][i].second;
			long long uv = adj[u][i].first;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v], v));
			}
		}

	}
	for (int i = 2; i <= n; i++) cout << d[i] << " ";
	return 0;
}
