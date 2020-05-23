#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100009];
long long getDirect(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return (long long) (a.second + b.second) * (long long) (a.first - b.first) + (long long) (b.second + c.second) * (long long) (b.first - c.first) + (long long) (c.second + a.second) * (long long) (c.first - a.first);
}
vector<pair<int, int> > up, down;
int main() {
    freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    pair<int, int> p1 = a[1], p2 = a[n];
    for (int i = 2; i <= n; i++) {
        if (i == n || getDirect(p1, a[i], p2) < 0) {
            while (up.size() >= 2 && getDirect(up[up.size() - 2], up[up.size() - 1], a[i]) >= 0) up.pop_back();
            up.push_back(a[i]);
        }
        if (i == n || getDirect(p1, a[i], p2) > 0) {
            while (down.size() >= 2 && getDirect(down[down.size() - 2], down[down.size() - 1], a[i]) <= 0) down.pop_back();
            down.push_back(a[i]);
        }
    }
    for (int i = 0; i < up.size(); i++) cout << up[i].first << " " << up[i].second << endl;
    for (int i = 0; i < up.size(); i++) cout << down[i].first << " " << down[i].second << endl;
    return 0;
}
