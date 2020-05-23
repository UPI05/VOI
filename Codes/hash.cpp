#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int base = 31;
long long hashA = 0;
long long hashB[10009];
long long po[10009];
string a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) hashA = (hashA * base + a[i] - 'a' + 1) % MOD;
    hashB[0] = 0;
    b = " " + b;
    for (int i = 1; i < b.length(); i++) hashB[i] = (hashB[i - 1] * base + b[i] - 'a' + 1) % MOD;
    po[0] = 1;
    for (int i = 1; i <= a.length(); i++) po[i] = (po[i - 1] * base) % MOD;
    cout << hashB[a.length()] << endl << hashA;
    return 0;
}
