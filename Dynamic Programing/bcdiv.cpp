#include <iostream>
#include <fstream>
using namespace std;
int t, n, k;
unsigned long long f[30][30];
unsigned long long C(int k, int n) {
    unsigned long long res = 1; int x = 1;
    for (int i = k + 1; i <= n; i++) {
        res *= i;
        if (x <= (n - k)) {
            res /= x;
            x++;
        }
    }
    return res;
}
int main() {
    for (int i = 1; i <= 25; i++) f[0][i] = f[i][0] = 0;
    f[0][0] = 1;
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = 0;
            for (int x = 1; x <= (i - j + 1); x++) {
                f[i][j] += f[i - x][j - 1] * C(x - 1, i - 1);
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << f[n][k] << endl;
    }
    return 0;
}
