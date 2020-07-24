#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000009;
int n;
pair<long long, long long> a[NMAX];
bool cw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) < 0;
}
bool ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) > 0;
}
int main() {
	freopen("bl.inp", "r", stdin);
	freopen("bl.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	pair<long long, long long> p1 = a[1], p2 = a[n];
	vector<pair<long long, long long> > up, down;
	up.push_back(p1); down.push_back(p1);
	for (int i = 2; i <= n; i++) {
		if (i == n || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i])) {
				up.pop_back();
			}
			up.push_back(a[i]);
		}
		if (i == n || ccw(p1, a[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) {
				down.pop_back();
			}
			down.push_back(a[i]);
		}
	}	
	vector<pair<long long, long long> > res;
	for (int i = 0; i < up.size(); i++) res.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--) res.push_back(down[i]);
	res.push_back(res[0]);
	long long ans = 0;
	for (int i = 0; i < res.size() - 1; i++) {
		ans += (res[i + 1].first + res[i].first) * (res[i + 1].second - res[i].second);	
	}
	ans = abs(ans);
	if (ans % 2) {
		cout << ans / 2 << ".5";
	} else {
		cout << ans / 2 << ".0";
	}
	return 0;
}
