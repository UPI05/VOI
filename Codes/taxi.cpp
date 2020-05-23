#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;
long long n, d[30][30], conf[30];
long long ans = 0, res = 100000000000000009;
bool check[30];
void backTrack(int k) {
    for (int i = 1; i <= n; i++) {
        //if ((k <= n / 2) && (i > n / 2)) break;
        //if ((k > n / 2) && (i <= n / 2)) continue;
        if (ans > res) continue;
        if (check[i]) continue;
        else {
            check[i] = 1;
        }
        conf[k] = i;
        ans += d[conf[k - 1]][conf[k]];
        if (k == n) {
            if (ans + d[conf[k]][0] < res) {
                unordered_map<int, bool> umap;
                bool ok = true;
                for (int i = 1; i <= n; i++) {
                    if (conf[i] <= n / 2) umap[conf[i]] = 1;
                    else {
                        if (!umap[conf[i] - n / 2]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) res = min(res, ans + d[conf[k]][0]);
            }
        } else {
            backTrack(k + 1);
        }
        ans -= d[conf[k - 1]][conf[k]];
        check[i] = 0;
    }
}
int main() {
    //freopen("taxi.inp", "r", stdin);
    //freopen("taxi.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        check[i] = 0;
        for (int j = 0; j <= n; j++) cin >> d[i][j];
    }
    conf[0] = 0;
    backTrack(1);
    cout << res;
    return 0;
}
