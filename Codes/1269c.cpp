#include <bits/stdc++.h>
using namespace std;
int n, k;
string s, a[200009];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    string t = "", ans = "";
    for (int i = 0; i < k; i++) t+= s[i];
    for (int i = 1; i <= n / k; i++) ans += t;
    for (int i = 0; i < n % k; i++) ans += t[i];
    cout << n << endl;
    if (ans >= s) {
        cout << ans << endl;
        return 0;
    }
    bool flag = 1;
    for (int i = (int) t.length() - 1; i >= 0; i--) {
        if (t[i] - '0' + flag == 10) {
            t[i] = '0';
        } else {
            t[i] = (t[i] - '0' + flag) + '0';
            flag = 0;
            break;
        }
    }
    if (flag) t = '1' + t;
    ans = "";
    for (int i = 1; i <= n / k; i++) ans += t;
    for (int i = 0; i < n % k; i++) ans += t[i];
    cout << ans << endl;
    return 0;
}
