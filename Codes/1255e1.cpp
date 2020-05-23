#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
long long res = 1e18;
bool x;
vector<int> pos;
int main() {
    //freopen("1255e1.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt += x;
        if (x) pos.push_back(i);
    }
    for (int i = 2; i <= cnt; i++) {
        if (cnt % i) continue;
        long long ans = 0;
        for (int j = 0; j < pos.size(); j+=i) {
            int k = (j * 2 + i - 1) / 2;
            for (int u = j; u < j + i; u++) {
                ans += abs(pos[u] - pos[k]);
            }
        }
        res = min(res, ans);
    }
    cout << ((res == 1e18) ? -1 : res);
    return 0;
}
