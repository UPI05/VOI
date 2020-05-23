#include <iostream>
#include <fstream>
using namespace std;
int n, res = 0, l, r;
string s;
int findZero(int l, int r, int k) {
    if (k == 0) return l;
    int Count = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '0') {
            Count++;
            if (Count == k) {
                return i;
            }
        }
    }
    return -1;
}
int findOne(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (s[i] == '1') return i;
    }
    return -1;
}
int main() {
    //freopen("beaustr.inp", "r", stdin);
    cin >> n;
    cin >> s;
    bool ok = true;
    for (int i = 0; i < n; i++) if (s[i] == '0') {
        ok = false;
        break;
    }
    if (ok) {
        cout << n << endl;
        return 0;
    }
    for (int k = 0; k <= n / 2; k++) {
        int ans = 0;
        l = 0, r = n - 1;
        int zero = findZero(l, r, k);
        if (zero == -1) continue;
        int one = findOne(zero + 1, r);
        if (one == -1) continue;
        zero = findZero(one + 1, r, k);
        if (zero == -1) continue;
        ans += (k * 2 + 1);
        do {
            one = findOne(zero + 1, r);
            if (one == -1) break;
            zero = findZero(one + 1, r, k);
            if (zero == -1) break;
            ans += k + 1;
        } while (1);
        res = max(res, ans);
    }
    cout << res << endl;
    return 0;
}
