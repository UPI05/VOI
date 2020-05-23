#include <iostream>
#include <fstream>
using namespace std;
const int base = 31;
const long long MOD = 1000000009;
int n, res = 1;
long long hashL[50009], hashR[50009], pow[50009];
string s;
int getHashL(int i, int j) {
    return (hashL[j] - hashL[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD;
}
int getHashR(int i, int j) {
    return (hashR[j] - hashR[i + 1] * pow[i - j + 1] + MOD * MOD) % MOD;
}
bool tryOdd(int k) {
    for (int i = k + 1; i <= n - k; i++) {
        if (getHashL(i - k, i - 1) == getHashR(i + k, i + 1)) return 1;
    }
    return 0;
}
bool tryEven(int k) {
    for (int i = 1; i <= n - k * 2 + 1; i++) {
        if (getHashL(i, i + k - 1) == getHashR(i + k * 2 - 1, i + k)) return 1;
    }
    return 0;
}
int main() {
    //freopen("paliny.inp", "r", stdin);
    cin >> n >> s;
    s = " " + s;
    hashL[0] = 0;
    for (int i = 1; i <= n; i++) hashL[i] = (hashL[i - 1] * base + s[i] - 'a' + 1) % MOD;
    hashR[n + 1] = 0;
    for (int i = n; i > 0; i--) hashR[i] = (hashR[i + 1] * base + s[i] - 'a' + 1) % MOD;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) pow[i] = (pow[i - 1] * base) % MOD;
    int l = 1, r = n / 2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (tryOdd(m)) {
            res = max(res, m * 2 + 1);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    l = 1, r = n / 2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (tryEven(m)) {
            res = max(res, m * 2);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res;
    return 0;
}
