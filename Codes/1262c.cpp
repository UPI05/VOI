#include <bits/stdc++.h>
using namespace std;
int t, n, k;
char pattern[2009], s[2009];
int main() {
    freopen("1262c.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= 2 * (k - 1); i+=2) {
            pattern[i] = '('; pattern[i + 1] = ')';
        }
        for (int i = 2 * (k - 1) + 1; i <= 2 * (k - 1) + (n - (k - 1) * 2) / 2; i++) {
            pattern[i] = '('; pattern[i + (n - (k - 1) * 2) / 2] = ')';
        }
        vector<pair<int, int> > res;
        for (int i = 1; i <= n; i++) {
            if (s[i] == pattern[i]) continue;
            for (int j = i + 1; j <= n; j++) {
                if (s[j] == pattern[i]) {
                    res.push_back(make_pair(i, j));
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
