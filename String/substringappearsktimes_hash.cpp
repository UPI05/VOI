#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
const int base = 31;
const long long MOD = 1000000009;
long long Hash[50009];
long long pow[50009];
int res = 0, n, k;
string s;
bool check(int x) {
    unordered_map<int, int> umap;
    for (int i = 1; i <= n - x + 1; i++) {
        int hashV = (Hash[i + x - 1] - Hash[i - 1] * pow[x] + MOD * MOD) % MOD;
        umap[hashV]++;
        if (umap[hashV] >= k) return 1;
    }
    return 0;
}
int main() {
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    Hash[0] = 0;
    for (int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % MOD;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) pow[i] = (pow[i - 1] * base) % MOD;
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            res = max(res, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res;
    return 0;
}
