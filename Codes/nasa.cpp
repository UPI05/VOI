#include <bits/stdc++.h>
using namespace std;
const int MAX = INT_MAX;
int n, m, a[100009], b[100009];
int main() {
    freopen("nasa.inp", "r", stdin);
    freopen("nasa.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (m >= n) {
        cout << a[1];
        return 0;
    }
    b[1] = a[1];
    for (int i = 2; i <= n; i++) b[i] = MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= i + m; j++) {
            if (j > n) continue;
            b[j] = min(b[j], b[i] + a[j]);
        }
    }
    int res = b[n];
    for (int i = n - 1; i > n - m ; i--) res = min(res, b[i]);
    cout << res;
    return 0;
}
