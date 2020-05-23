#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int n, m, d[100009], u, v, w;
bool check[100009];
struct dt {
    int node, weight;
};
struct cmp {
    bool operator() (dt a, dt b) {
        return a.weight > b.weight;
    }
};
vector<dt> adj[100009];
priority_queue<dt, vector<dt>, cmp> pq;
int main() {
    freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        dt x;
        cin >> u >> v >> w;
        x.node = v; x.weight = w;
        adj[u].push_back(x);
        x.node = u;
        adj[v].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        check[i] = 0;
        d[i] = MAX;
    }
    d[1] = 0;
    dt x;
    x.node = 1; x.weight = 0;
    pq.push(x);
    while (pq.size()) {
        x = pq.top();
        pq.pop();
        check[x.node] = 1;
        for (int i = 0; i < adj[x.node].size(); i++) {
            if (!check[adj[x.node][i].node]) {
                if (d[adj[x.node][i].node] > d[x.node] + adj[x.node][i].weight) {
                    d[adj[x.node][i].node] = d[x.node] + adj[x.node][i].weight;
                    dt y;
                    y.node = adj[x.node][i].node;
                    y.weight = d[adj[x.node][i].node];
                    pq.push(y);
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) cout << d[i] << endl;
    return 0;
}
