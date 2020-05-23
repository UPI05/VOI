#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, m, a[30], res = 0, ans = 0, u, v;
vector<int> b[30];
bool conf[30];
void backTrack(int k) {
    for (int i = 0; i <= 1; i++) {
        conf[k] = i;
        if (i == 1) res += a[k];
        if (k == n) {
            bool ok = true;
            for (int i = 1; i <= n; i++) {
                if (conf[i] && b[i].size()) {
                    for (int j = 0; j < b[i].size(); j++) {
                        if (!conf[b[i][j]]) {
                            ok = false;
                            goto st;
                        }
                    }
                }
            }
            st:
            if (ok) {
                ans = max(ans, res);
            }
        } else {
            backTrack(k + 1);
        }
        if (i == 1) {
            res -= a[k];
        }
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        b[u].push_back(v);
    }
    backTrack(1);
    cout << ans;
    return 0;
}
