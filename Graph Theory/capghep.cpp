#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1009;
int n, m, u, v, mX[NMAX], mY[NMAX], tr[NMAX];
bool matrix[NMAX][NMAX];
int bfs() {
	fill(tr + 1, tr + m + 1, 0);
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!mX[i]) q.push(i);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= m; i++) {
			if (!tr[i] && matrix[x][i]) {
				tr[i] = x;
				if (!mY[i]) return i;
				q.push(mY[i]);
			}
		}
	}
	return 0;
}
int main() {
	freopen("capghep.inp", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) matrix[i][j] = 0; 
	}
	while (cin >> u >> v) matrix[u][v] = 1;
	fill(mX + 1, mX + n + 1, 0); // mX[i] la dinh thuoc Y duoc ghep voi dinh i thuoc X
	fill(mY + 1, mY + m + 1, 0); // mY[i] la dinh thuoc X duoc ghep voi dinh i thuoc Y
	while (int f = bfs()) {
		while (f) {
			int x = tr[f];
			int next = mX[x];
			mX[x] = f;
			mY[f] = x;
			f = next;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += (mX[i] != 0);
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		if (mX[i]) cout << i << " " << mX[i] << endl;
	}
	return 0;
}
