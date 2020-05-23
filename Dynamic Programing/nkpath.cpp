#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long long n, m, a[109][109], f[109][109], res = 0;
int main() {
    //freopen("nkpath.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; f[i][j] = 0;
        }
        f[i][1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = i; x <= n; x++) {
                for (int y = j; y <= m; y++) {
                    if (x == i && y == j || (j == m)) continue;
                    if (__gcd(a[i][j], a[x][y]) != 1) {
                        f[x][y] += f[i][j];
                        f[x][y] %= 1000000000;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i][m] %= 1000000000;
        res += f[i][m];
        res %= 1000000000;
    }
    cout << res;
    return 0;
}
