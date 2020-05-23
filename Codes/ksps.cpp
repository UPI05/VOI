#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int p, q;
string s, t = "";
int main() {
    freopen("ksps.inp", "r", stdin);
    freopen("ksps.out", "w", stdout);
    cin >> p >> q;
    cin >> s;
    t += (p / q) + '0';
    p = p % q;
    for (int i = 1; i <= 2000002; i++) {
        t += (char) ((p * 10) / q) + '0';
        p *= 10;
        p = p % q;
    }
    cout << t.find(s) + 1;
    return 0;
}
