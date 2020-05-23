#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;
int n, m, res, len = 0, u, v, w, root;
vector<pair<int, int> > adj[109];
bool check[109];
void dfs(int k, int ans) {
    check[k] = 1;
    len++;
    for (int i = 0; i < adj[k].size(); i++) {
        if (!check[adj[k][i].first]) {
            dfs(adj[k][i].first, ans + adj[k][i].second);
        } else if (len > 2 && adj[k][i].first == root) {
            res = min(res, ans + adj[k][i].second);
        }
    }
    check[k] = 0;
    len--;
}
int main() {
    freopen("trip.inp", "r", stdin);
    //freopen("trip.out", "w", stdout);
    for (int i = 1; i <= 100; i++) check[i] = 0;
    while (cin >> n && n != -1) {
        for (int i = 1; i <= n; i++) adj[i].clear();
        cin >> m;
        while (m--) {
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        res = 1000000009;
        for (int i = 1; i <= n; i++) {
            root = i;
            dfs(i, 0);
        }
        if (res != 1000000009) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}
