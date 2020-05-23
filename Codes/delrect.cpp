#include <bits/stdc++.h>
using namespace std;
int n, m, b[10009][10009], res = 0;
struct dt {
    int x1, x2, y1, y2;
} a[5009];
int main() {
    //freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) b[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x1 >> a[i].x2 >> a[i].y1 >> a[i].y2;
        for (int x = a[i].x1; x <= a[i].x2; x++) {
            for (int y = a[i].y1; y <= a[i].y2; y++) {
                b[x][y]++;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int ans = 0;
            for (int x = a[i].x1; x <= a[i].x2; x++) {
                for (int y = a[i].y1; y <= a[i].y2; y++) {
                    b[x][y]--;
                }
            }
            for (int x = a[j].x1; x <= a[j].x2; x++) {
                for (int y = a[j].y1; y <= a[j].y2; y++) {
                    b[x][y]--;
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (b[i][j] == 0) {
                        ans++;
                    }
                }
            }
            res = max(res, ans);
            for (int x = a[i].x1; x <= a[i].x2; x++) {
                for (int y = a[i].y1; y <= a[i].y2; y++) {
                    b[x][y]++;
                }
            }
            for (int x = a[j].x1; x <= a[j].x2; x++) {
                for (int y = a[j].y1; y <= a[j].y2; y++) {
                    b[x][y]++;
                }
            }
        }
    }
    cout << res;
    return 0;
}
