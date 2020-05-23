#include <bits/stdc++.h>
using namespace std;
int n, m;
const int NMAX = 2e5 + 9;
long long prefix[NMAX], res[NMAX];
int a[NMAX];
int main() {
    //freopen("1253c.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        if (i - m > 0) {
            res[i] = res[i - m] + prefix[i];
        } else {
            res[i] = prefix[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}
