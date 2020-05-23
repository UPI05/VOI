#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m, num[10005], low[10005],
cnt=0, connect[10005], numSCC=0;
vector<int> a[10005], S;
void dfs(int u) {
    low[u] = num[u] = cnt++;
    S.push_back(u);
    connect[u] = 1;
    for(int v : a[u]) {
        if (num[v] == -1) dfs(v);
        if (connect[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        numSCC++;
        while(1) {
            int v = S.back(); S.pop_back();
            connect[v] = 0;
            if (u == v) break;
        }
    }
}
int main() {
    freopen("a.inp", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
    fill(num + 1, num + n + 1, -1);
    fill(low + 1, low + n + 1, 1);
    fill(connect + 1, connect + n + 1, 0);
    for(int u = 1; u <= n; u++)
        if (num[u] == -1) dfs(u);
    cout << numSCC;
    return 0;
}
