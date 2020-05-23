#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
const int NMAX = 1009;
int n, m, u, v;
vector<vector<int> > adj(NMAX);
bool check[NMAX];
int d[NMAX];
void bfs() {
    queue<int> q;
    q.push(1);
    check[1] = 1;
    d[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            if (!check[adj[x][i]]) {
                q.push(adj[x][i]);
                check[adj[x][i]] = 1;
                d[adj[x][i]] = d[x] + 1;
            }
        }
    }
}
int main() {
    freopen("bfs.inp", "r", stdin);
    freopen("bfs.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) check[i] = 0;
    bfs();
    for (int i = 1; i <= n; i++) cout << d[i] << endl;
    return 0;
}
