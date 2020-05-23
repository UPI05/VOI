#include <bits/stdc++.h>
using namespace std;
int t, n, a[200009], pos[200009];
int main() {
    freopen("1257c.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[i] = 0;
        }
        int res = 2e6;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (pos[a[i]] == 0) pos[a[i]] = i;
            else {
                ok = true;
                res = min(res, i - pos[a[i]] + 1);
                pos[a[i]] = i;
            }
        }
        if (ok) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}
