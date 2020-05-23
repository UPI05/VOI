#include <bits/stdc++.h>
using namespace std;
int n, m, k, p, a[109];
bool check[109];
pair<int, int> b[109];
int main() {
    freopen("1227d1.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> k >> p;
        if (k == n) {
            cout << a[p] << endl;
            continue;
        }
        int val, cnt = 0;
        for (int j = 1; j <= n; j++) check[j] = 0;
        if (b[n].first != b[n - k + 1].first) {
            for (int j = n; j > n - k + 1; j--) {
                if (b[j].first != b[n - k + 1].first) {
                    check[b[j].second] = 1;
                    cnt++;
                } else {
                    break;
                }
            }
        }
        vector<int> res;
        val = b[n - k + 1].first;
        cnt = k - cnt;
        for (int i = 1; i <= n; i++) {
            if (check[i]) {
                res.push_back(a[i]);
            } else if (a[i] == val && cnt > 0) {
                res.push_back(a[i]);
                cnt--;
            }
        }
        cout << res[p - 1] << endl;
    }
    return 0;
}
