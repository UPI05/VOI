#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int NMAX = 10009;
int n, m, p[NMAX], res = 0;
struct dt {
    int u, v, w;
} edges[NMAX];
bool cmp(dt a, dt b) {
    return a.w < b.w;
}
int root(int k) {
    if (p[k] == k) return k;
    p[k] = root(p[k]);
    return p[k];
}
void connect(int u, int v, int id) {
    u = root(u); v = root(v);
    if (u != v) {
        p[u] = v;
        res += edges[id].w;
    }
}
int main() {
    freopen("kruskal.inp", "r", stdin);
    //freopen("kruskal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        p[i] = i;
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        connect(edges[i].u, edges[i].v, i);
    }
    cout << res;
    return 0;
}
