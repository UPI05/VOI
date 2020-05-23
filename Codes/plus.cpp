#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
long long a, b;
vector<string> s;
int main() {
    //freopen("plus.inp", "r", stdin);
    cin >> a >> b;
    while (a != b) {
        if (a % 2 == 0 && b % 2 == 0) {
            long long g = __gcd(a, b);
            a /= g; b /= g;

        } else if (a % 2 && b % 2) {
            if (a < b) {
                long long x = min(a, b);
                a += x; b += x;
                s.push_back("B+=A");
                s.push_back("A+=A");
            } else {
                long long x = min(a, b);
                a += x; b += x;
                s.push_back("A+=B");
                s.push_back("B+=B");
            }
        } else if (a % 2 && b % 2 == 0) {
            a *= 2;
            s.push_back("A+=A");
        } else {
            b *= 2;
            s.push_back("B+=B");
        }
    }
    cout << s.size() << endl;
    for (int i = 0; i < s.size(); i++) cout << s[i] << endl;
    return 0;
}
