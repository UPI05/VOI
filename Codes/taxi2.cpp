#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;
long long n, d[30][30], conf[30];
long long ans = 0, res = 100000000000000009;
bool check[30];
unordered_map<int, bool> umap;
void backTrack(int k) {
    for (int i = 1; i <= n; i++) {
        if (ans > res) continue;
        if (check[i]) continue;
        else {
            check[i] = 1;
        }
        if (i <= n / 2) umap[i] = 1;
        else {
            if (!umap[i - n / 2]) {
                check[i] = 0;
                continue;
            }
        }
        conf[k] = i;
        ans += d[conf[k - 1]][conf[k]];
        if (k == n) {
            res = min(res, ans + d[conf[k]][0]);
        } else {
            backTrack(k + 1);
        }
        ans -= d[conf[k - 1]][conf[k]];
        check[i] = 0;
        if (i <= n / 2) umap[i] = 0;
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
