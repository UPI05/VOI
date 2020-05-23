#include <bits/stdc++.h>
using namespace std;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	return 0;
}
