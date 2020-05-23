#include <iostream>
#include <fstream>
using namespace std;
int n, W, f[50009], w[50009], a[50009];
int main() {
    freopen("wiseq.inp", "r", stdin);
    freopen("wiseq.out", "w", stdout);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {cin >> a[i]; f[i] = 1; w[i] = a[i];}
    for (int i = 1; i <= n; i++) {
        if (w[i] >= W) continue;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] > a[i] && f[i] + 1 > f[j]) {
                w[j] = w[i] + a[j];
                f[j] = f[i] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (w[i] <= W) {
            res = max(res, f[i]);
        }
    }
    cout << res;
    return 0;
}
