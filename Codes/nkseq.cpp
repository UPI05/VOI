#include <iostream>
#include <fstream>
using namespace std;
int n, a[100009], sum[100009], f[100009];
int main() {
    //freopen("nkseq.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum[0] = 0;
    for (int i = n + 1; i < 2 * n; i++) {
        a[i] = a[i - n];
    }
    for (int i = 1; i < 2 * n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    f[n] = a[n];
    for (int i = n + 1; i < 2 * n; i++) {
        f[n] = min(f[n], sum[i] - sum[n - 1]);
    }
    for (int i = n - 1; i > 0; i--) {
        f[i] = min(a[i] + f[i + 1], a[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (f[i] > 0);
    cout << res;
    return 0;
}
