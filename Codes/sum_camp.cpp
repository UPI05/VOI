#include <iostream>
#include <fstream>
using namespace std;
const int NMAX = 100009;
int n, m, k, q, u, v;
char c;
int pk[NMAX];
bool d[10009][10009];
int rootK(int k) {
    if (pk[k] == k) return k;
    return (pk[k] = rootK(pk[k]));
}
void connectK(int u, int v) {
    u = rootK(u); v = rootK(v);
    if (u != v) pk[u] = v;
}
int main() {
    freopen("sum_camp.inp", "r", stdin);
    freopen("sum_camp.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        pk[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        d[u][v] = d[v][u] = 1;
    }
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        connectK(u, v);
    }
    cin >> q;
    while (q--) {
        cin >> c;
        if (c == 'F') {
            cin >> u >> v;
            d[u][v] = d[v][u] = 1;
        } else if (c == 'T') {
            cin >> u >> v;
            connectK(u, v);
        } else {
            cin >> k;
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (i == k) continue;
                if (d[i][k] && rootK(i) == rootK(k)) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
