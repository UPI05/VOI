#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
pair<int, int> p;
vector<int> adj[200009];
vector<pair<int, int> > ans;
bool check[200009];
void dfs(int k) {
    check[k] = 1;
    p.first = min(p.first, k);
    p.second = max(p.second, k);
    for (int i = 0; i < adj[k].size(); i++) {
        if (!check[adj[k][i]]) {
            dfs(adj[k][i]);
        }
    }
}
int main() {
    //freopen("1253d.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >>  n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) check[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            p.first = 2e5;
            p.second = 1;
            dfs(i);
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end());
    int res = 0;
    p = ans[0];
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i].first > p.second) {
            p.first = ans[i].first; p.second = ans[i].second;
            continue;
        }
        res++;
        p.second = max(ans[i].second, p.second);
    }
    cout << res;
    return 0;
}
