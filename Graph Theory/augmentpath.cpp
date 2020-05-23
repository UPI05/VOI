#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, m, u, v, matchR[109], res = 0;
bool check[109];
vector <int> adjList[209];
vector <pair<int, int> > edges;
bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}
bool findPath(int u) {
    for (int v : adjList[u]) {
        if (!check[v]) {
            check[v] = 1;
            if (matchR[v] < 0 || findPath(matchR[v])) {
                matchR[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
void matching() {
    fill(matchR + 1, matchR + n + 3 + m + 1, -1);
    for (int i = 1; i <= n; i++) {
        fill(check + 1, check + n + 3 + m + 1, 0);
        if (findPath(i)) {
            res++;
        }
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    //int k;
    cin >> n >> m;
    while (cin >> u >> v) {
        v += n;
        adjList[u].push_back(v);
    }
    matching();
    for (int i = n + 1; i <= n + m; i++) if (matchR[i] != -1) edges.push_back(make_pair(matchR[i], i - n));
    sort(edges.begin(), edges.end(), cmp);
    cout << res << endl;
    for (int i = 0; i < edges.size(); i++) cout << edges[i].first << " " << edges[i].second << endl;
    return 0;
}
