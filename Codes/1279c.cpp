#include <bits/stdc++.h>
using namespace std;
int t, n, m, pos[100009], x, a[100009];
int main() {
    //freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            pos[x] = i;
        }
        for (int i = 1; i <= m; i++) cin >> a[i];
        long long res = (long long) pos[a[1]] * 2 - 1, pri = pos[a[1]];
        for (int i = 2; i <= m; i++) {
            if (pos[a[i]] > pri) {
                res += ((long long) (pos[a[i]] - (i - 1)) * 2 - 1);
                pri = pos[a[i]];
            } else {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
