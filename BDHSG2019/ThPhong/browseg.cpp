#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int x, y, u, v, s, trace[300009];
long long res = 1, n;
vector<int> adj[300009];
bool check[300009];
void dfs(int k) {
    check[k] = 1;
    if (k == y) return;
    for (int i = 0; i < adj[k].size(); i++) if (!check[adj[k][i]]) {
        trace[adj[k][i]] = k;
        dfs(adj[k][i]);
    }
}
void dfs2(int k, int x) {
    check[k] = 1;
    s++;
    for (int i = 0; i < adj[k].size(); i++) {
        if (!check[adj[k][i]] && adj[k][i] != x) dfs2(adj[k][i], x);
    }
}
int main() {
    freopen("browseg.inp", "r", stdin);
    freopen("browseg.out", "w", stdout);
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) check[i] = 0, trace[i] = 0;
    dfs(x);
    v = trace[y];
    u = y;
    while (trace[u] != x) u = trace[u];
    for (int i = 1; i <= n; i++) check[i] = 0;
    s = 0;
    dfs2(x, u);
    res *= s;
    for (int i = 1; i <= n; i++) check[i] = 0;
    s = 0;
    dfs2(y, v);
    res *= s;
    cout << (n - 1) * n - res;
    return 0;
}
