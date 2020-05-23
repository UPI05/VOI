#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, long long> a[309];
long long square(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    return ((a.first - b.first) * (a.second + b.second) + (b.first - c.first) * (b.second + c.second) + (c.first - a.first) * (c.second + a.second));
}
int main() {
    //freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    long long res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long left = 0, right = 0;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                if (square(a[i], a[j], a[k]) < 0) {
                    right = max(right, abs(square(a[i], a[j], a[k])));
                } else {
                    left = max(left, abs(square(a[i], a[j], a[k])));
                }
            }
            if (left && right) {
                res = max(res, left + right);
            }
        }
    }
    cout << res;
    return 0;
}
