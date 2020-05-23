// Longest common substring - Xâu con chung dài nhất
#include <iostream>
#include <fstream>
using namespace std;
string s, t;
int f[10009][10009];
int main() {
    freopen("lcs.inp", "r", stdin);
    //freopen("lcs.out", "w", stdout);
    cin >> s >> t;
    s = " " + s; t = " " + t;
    for (int i = 0; i < s.length(); i++) f[i][0] = 0;
    for (int i = 0; i < t.length(); i++) f[0][i] = 0;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 1; j < t.length(); j++) {
            if (s[i] == t[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j - 1], max(f[i - 1][j], f[i][j - 1]));
        }
    }
    cout << f[s.length() - 1][t.length() - 1];
    return 0;
}
