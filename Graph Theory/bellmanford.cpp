#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int MAX = 100000000;
int n, m, s, d[10009], trace[10009];
struct data {
    int u, v, w;
} edges[10009];
int main() {
    freopen("bellmanford.inp", "r", stdin);
    freopen("bellmanford.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    for (int i = 1; i <= n; i++) {d[i] = MAX; trace[i] = 0;}
    d[s] = 0;
    for (int i = 1; i < n; i++) {
        bool ok = false;
        for (int j = 1; j <= m; j++) {
            if (d[edges[j].v] > (d[edges[j].u] + edges[j].w)) {
                trace[edges[j].v] = edges[j].u;
                d[edges[j].v] = d[edges[j].u] + edges[j].w;
                ok = true;
            }
            if (d[edges[j].u] > (d[edges[j].v] + edges[j].w)) {
                trace[edges[j].u] = edges[j].v;
                d[edges[j].u] = d[edges[j].v] + edges[j].w;
                ok = true;
            }
        }
        if (!ok) break;
    }
    for (int i = 1; i <= n; i++) cout << d[i] << endl;
    return 0;
}
