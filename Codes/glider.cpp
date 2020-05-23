#include <iostream>
#include <fstream>
using namespace std;
int n, h, sum[300009], res = 0;
pair<int, int> pos[300009];
int binFind(int l, int r, int p) {
    int ans;
    while (l <= r) {
        int m = (l + r) / 2;
        if (sum[m] - sum[p] >= h) {
            r = m - 1;
        } else {
            ans = m;
            l = m + 1;
        }
    }
    return ans;
}
int main() {
    //freopen("glider.inp", "r", stdin);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> pos[i].first >> pos[i].second;
    sum[1] = 0;
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + (pos[i].first - pos[i - 1].second);
    }
    for (int i = 1; i <= n; i++) {
        int k = binFind(i, n, i);
        res = max(res, h + (pos[k].second - pos[i].first - (sum[k] - sum[i])));
    }
    cout << res << endl;
    return 0;
}
