#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
string s;
vector<int> res;
const int base = 31;
const long long MOD = 1000000009;
long long hashA[1000009];
long long pow[1000009];
int getHash(int i, int j) {
    return (hashA[j] - hashA[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD;
}
int main() {
    //freopen("strkary.inp", "r", stdin);
    cin >> s;
    hashA[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++) hashA[i] = (hashA[i - 1] * base + s[i] - 'a' + 1) % MOD;
    pow[0] = 1;
    for (int i = 1; i <= (s.length()); i++) pow[i] = (pow[i - 1] * base) % MOD;
    res.push_back(1);
    for (int i = 2; i <= s.length(); i++) {
        if ((int) s.length() % i) continue;
        unordered_map<long long, bool> umap;
        long long s2 = s[0] - 'a' + 1;
        for (int j = 1; j < ((int) (s.length()) / i); j++) {
            s2 = (s2 * base + s[j] - 'a' + 1) % MOD;
        }
        long long s3 = 0;
        long long x = s2;
        int t = 0;
        do {
            umap[(s2 - s3 * pow[((int) s.length() / i)] + MOD * MOD) % MOD] = 1;
            s3 = (s3 * base + s[t] - 'a' + 1) % MOD;
            s2 = (s2 * base + s[t] - 'a' + 1) % MOD;
            t++;
        } while ((s2 - s3 * pow[((int) s.length() / i)] + MOD * MOD) % MOD != x);
        bool ok = true;
        for (int j = 1; j < i; j++) {
            long long s4 = getHash(j * ((int) s.length() / i), j * ((int) s.length() / i) + ((int) s.length() / i) - 1);
            if (!umap[s4]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}
