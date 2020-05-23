#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
int n;
const int MOD = 1e9 + 7;
long long arr[10009], m, res = 0;
map<long long, long long> umap[10009];
int main() {
    //freopen("triple.inp", "r", stdin);
    //freopen("triple.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            umap[j][arr[i]]++;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long k = (m - arr[i] - arr[j]);
            res += (umap[n][k] - umap[j][k]) % MOD;
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
