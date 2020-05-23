#include <bits/stdc++.h>
using namespace std;
int t, n, a[100009], b[1000000];
int main() {
    //freopen("1278c.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int cntRed = 0, cntBlue = 0;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                cntRed++;
            } else {
                cntBlue++;
            }
        }
        if (cntRed == cntBlue) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i <= 200000 + 5; i++) b[i] = 0;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (a[i] == 1) {
                cnt++;
            } else {
                cnt--;
            }
            if (b[cnt + 100000] == 0) b[cnt + 100000] = i - n;
        }
        int res = 1e9, red = 0, blue = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] == 1) {
                red++;
            } else {
                blue++;
            }
            if (b[cntRed - cntBlue - (red - blue) + 100000] == 0) continue;
            res = min(res, b[cntRed - cntBlue - (red - blue) + 100000] + n - i + 1);
        }
        int k = cntRed - cntBlue;
        cntRed = cntBlue = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] == 1) {
                cntRed++;
            } else {
                cntBlue++;
            }
            if (cntRed - cntBlue == k) {
                res = min(res, n - i + 1);
                break;
            }
        }
        cntRed = cntBlue = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (a[i] == 1) {
                cntRed++;
            } else {
                cntBlue++;
            }
            if (cntRed - cntBlue == k) {
                res = min(res, i - n);
                break;
            }
        }
        if (res == 1e9) cout << 2 * n << endl;
        else cout << res << endl;
    }
    return 0;
}
