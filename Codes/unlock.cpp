#include <iostream>
#include <fstream>
using namespace std;
int n, m, a[100009];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("unlock.inp", "r", stdin);
    freopen("unlock.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n + 1; i < 2 * n; i++) a[i] = a[i - n] + m;
    for (int i = 1; i <= n; i++) {
        int p = a[(i + i + n - 1) / 2];

    }

    return 0;
}
