#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int MAX = 100000000;
int n, m, k, u, v, w, d[109][109], trace[109][109];
int main() {
    freopen("floyd.inp", "r", stdin);
    freopen("floyd.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = MAX;
        }
        d[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        d[u][v] = w; d[v][u] = w;
        trace[u][v] = v; trace[v][u] = u;
    }
    for (int x = 1; x <= n; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][x] + d[x][j]) {
                    d[i][j] = d[i][x] + d[x][j];
                    trace[i][j] = trace[i][x];
                }
            }
        }
    }
    while (k--) {
        cin >> u >> v >> w;
        if (u == 0) cout << d[v][w] << endl;
        else {
            vector <int> res;
            res.push_back(w);
            while (trace[v][w] != w) {
                w = trace[v][w];
                res.push_back(w);
            }
            res.push_back(v);
            cout << res.size() << " ";
            for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " "; cout << endl;
        }
    }
    return 0;
}
