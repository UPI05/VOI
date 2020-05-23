#include <bits/stdc++.h>
using namespace std;
#define _DEBUG 1
long long t, n, k;
string s;
int main() {
    if (_DEBUG) freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] =='1') {
                ++cnt;
            } else {
                if (k >= cnt) {
                    ans.push_back(-1);
                    k -= cnt;
                } else {
                    ans.push_back(cnt - k);
                    ans.push_back(-1);
                    cnt = k;
                    k = 0;
                }
            }
        }
        ans.push_back(cnt);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == -1) cout << 0;
            else {
                for (int j = 1; j <= ans[i]; j++) cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}
