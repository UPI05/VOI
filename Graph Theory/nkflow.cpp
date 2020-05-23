#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const int MAX = 100000000;
int n, m, s, t, u, v, c, parent[1009], arr[1009][1009] = {0};
long long maxFlow = 0;
bool check[1009];
struct data {
    int node, cap;
};
vector <data> adjList[1009];
bool findPath() {
    fill(check + 1, check + n + 1, 0);
    parent[s] = -1;
    queue <int> q;
    q.push(s);
    check[s] = 1;
    while (q.size()) {
        int x = q.front(); q.pop();
        /*for (int i = 0; i < adjList[x].size(); i++) {
            if (!check[adjList[x][i].node] && arr[x][adjList[x][i].node] > 0) {
                q.push(adjList[x][i].node);
                check[adjList[x][i].node] = 1;
                parent[adjList[x][i].node] = x;
            }
        }*/
        for (int i = 1; i <= n; i++) {
            if (!check[i] && arr[x][i] > 0) {
                q.push(i);
                check[i] = 1;
                parent[i] = x;
            }
        }
    }
    return check[t];
}
void searchMaxFlow() {
    while (findPath()) {
        int minFlowOnPath = MAX;
        int x = t;
        while (parent[x] != -1) {
            minFlowOnPath = min(minFlowOnPath, arr[parent[x]][x]);
            x = parent[x];
        }
        x = t;
        while (parent[x] != -1) {
            arr[parent[x]][x] -= minFlowOnPath;
            arr[x][parent[x]] += minFlowOnPath;
            x = parent[x];
        }
        maxFlow += minFlowOnPath;
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
       // data x; x.node = v; x.cap = c;
        arr[u][v] = c;
        //adjList[u].push_back(x);
    }
    searchMaxFlow();
    cout << maxFlow;
    return 0;
}
