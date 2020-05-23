#include <iostream>
#include <fstream>
using namespace std;
int n, l, x, Min, sum[6009], f[6009];
int main() {
    freopen("ptrang.inp", "r", stdin);
    freopen("ptrang.out", "w", stdout);
    cin >> n >> l;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    f[1] = l - sum[1];
    for (int i = 2; i <= n; i++) {
        Min = 1009;
        for (int j = i; j >= 1; j--) {
            if (l - (sum[i] - sum[j - 1]) >= 0) {
                Min = min(Min, max(l - (sum[i] - sum[j - 1]), f[j - 1]));
            }
        }
        f[i] = Min;
    }
    cout << f[n];
    return 0;
}
