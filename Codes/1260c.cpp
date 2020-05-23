#include <bits/stdc++.h>
using namespace std;
int t, r, b, k;
int main() {
    freopen("1260c.inp", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> r >> b >> k;
        if (r == b) {
            cout << "OBEY" << endl;
            continue;
        }
        if (r > b) swap(r, b);
        if ((b - r) % r) {
            r = (b - r) / r;
        } else {
            r = (b - r) / r - 1;
        }
        r += 1;
        if (r >= k) cout << "REBEL" << endl;
        else cout << "OBEY" << endl;
    }
    return 0;
}
