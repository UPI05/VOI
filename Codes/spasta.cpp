#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
long long m, k, n, t;
int a[100009];
int main() {
    freopen("spasta.inp", "r", stdin);
    freopen("spasta.out", "w", stdout);
    cin >> m >> k >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (m - n < k) {
        cout << -1;
        return 0;
    }
    long long res;
    if (k % 2) {
        res = k * (k / 2) + k + k * t;
    } else {
        res = (1 + k) * (k / 2) + k * t;
    }
    int remain = 0;
    unordered_map<int, bool> umap;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= k) {
            remain++;
            res -= (t + a[i]);
        } else umap[a[i]] = 1;
    }
    for (int i = k + 1; i <= 10000000000; i++) {
        if (!remain) break;
        if (!umap[i]) {
            remain--;
            res += (i + t);
        }
    }
    cout << res;
    return 0;
}
