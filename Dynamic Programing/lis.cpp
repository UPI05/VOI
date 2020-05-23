#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int NMAX = 100009;
const int MAX = 1000000009;
int n, arr[NMAX], f[NMAX], res = 1;
int main() {
    freopen("lis.inp", "r", stdin);
    //freopen("lis.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = MAX;
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(f + 1, f + n + 1, arr[i]) - f;
        f[k] = arr[i];
        res = max(res, k);
    }
    cout << res;
    return 0;
}
