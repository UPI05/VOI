#include <iostream>
#include <fstream>
using namespace std;
const int MOD = 1e9 + 7;
int t, n;
long long f[1009], m[1009][1009];
void calcC() {
    for (int i = 0; i <= 1000; i++) m[i][0] = 1, m[i][i] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            m[i][j] = (m[i - 1][j - 1] + m[i - 1][j]) % MOD;
        }
    }
}
int main() {
    freopen("taphop.inp", "r", stdin);
    freopen("taphop.out", "w", stdout);
    calcC();
    f[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        f[i] = 0;
        for (int j = 1; j <= i; j++) {
            f[i] += (f[i - j] * m[i - 1][j - 1]) % MOD;
            f[i] %= MOD;
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
