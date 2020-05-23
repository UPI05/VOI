#include <iostream>
#include <fstream>
using namespace std;
int n, k, c[3009], a[3009], f[109][3009];
int main() {
    //freopen("drone.inp", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) f[i][j] = 0;
    }
    f[1][1] = c[1];

    return 0;
}
