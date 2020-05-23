#include <iostream>
#include <fstream>
using namespace std;
int t, n, m, a[109], b[109], f[109][109];
int main() {
    //freopen("lcs2x.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) f[i][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] != b[j]) continue;
                f[i][j] = max(f[i][j], 1);
                for (int x = 1; x < i; x++) {
                    for (int y = 1; y < j; y++) {
                        if (a[x] == b[y] && a[x] * 2 <= a[i]) {
                            f[i][j] = max(f[i][j], f[x][y] + 1);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                res = max(f[i][j], res);
            }
        }
        cout << res << endl;
    }
    return 0;
}
