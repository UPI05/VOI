#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int n, m, d[1009], trace[1009];
struct dt {
    int u, v, w;
} adj[1009];
int main() {
    freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> adj[i].u >> adj[i].v >> adj[i].w;
    }
    for (int i = 1; i <= n; i++) {
        d[i] = MAX;
        trace[i] = 0;
    }
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 1; j <= m; j++) {
            if (d[adj[j].v] > d[adj[j].u] + adj[j].w) {
                ok = true;
                d[adj[j].v] = d[adj[j].u] + adj[j].w;
            }
            if (d[adj[j].u] > d[adj[j].v] + adj[j].w) {
                ok = true;
                d[adj[j].u] = d[adj[j].v] + adj[j].w;
            }
        }
        if (!ok) break;
        if (i == n && ok) {
            cout << "FUCK";
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << endl;
    return 0;
}
