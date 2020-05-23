#include <bits/stdc++.h>
using namespace std;
int n, m, d, c[1009], sum[1009], ans[1009];
int main() {
    cin >> n >> m >> d;
    sum[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        sum[i] = sum[i - 1] + c[i];
    }
    if ((double) (n - sum[m]) / (m + 1) > d - 1) {
        cout << "NO" << endl;
        return 0;
    }
    int last = 0;
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = min(last + d, n); j > last; j--) {
            if ((sum[m] - sum[i - 1]) <= (n - j + 1)) {
                last = j + c[i] - 1;
                for (int k = j; k <= last; k++) ans[k] = i;
                break;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
