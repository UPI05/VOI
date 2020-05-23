#include <iostream>
#include <fstream>
using namespace std;
int t, n, arr[500009], f[500009];
int main() {
    freopen("ternaryequal.inp", "r", stdin);
    freopen("ternaryequal.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 3) cout << 0 << endl;
        else {
            sum /= 3;
            int x = 0;
            f[n + 1] = 0;
            for (int i = n; i > 0; i--) {
                x += arr[i];
                if (x == sum) f[i] = f[i + 1] + 1;
                else f[i] = f[i + 1];
            }
            x = 0;
            int res = 0;
            for (int i = 1; i <= n; i++) {
                x += arr[i];
                if (x == sum) res += f[i + 2];
            }
            cout << res << endl;
        }
    }
}
