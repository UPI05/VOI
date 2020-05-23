#include <iostream>
#include <fstream>
using namespace std;
const int base = 31;
const long long MOD = 1000000009;
long long hashA[1000009];
long long pow[1000009];
string a, b;
int main() {
    cin >> a >> b;
    a = " " + a;
    long long hashB = 0;
    for (int i = 0; i < b.length(); i++) hashB = (hashB * base + b[i] - 'a' + 1) % MOD;
    hashA[0] = 0;
    for (int i = 1; i < a.length(); i++) hashA[i] = (hashA[i - 1] * base + a[i] - 'a' + 1) % MOD;
    pow[0] = 1;
    for (int i = 1; i <= a.length(); i++) pow[i] = (pow[i - 1] * base) % MOD;
    for (int i = 1; i <= a.length() - b.length(); i++) {
        long long hashI = (hashA[i + b.length() - 1] - hashA[i - 1] * pow[b.length()] + MOD * MOD) % MOD;
        if (hashB == hashI) cout << i << " ";
    }
    return 0;
}
