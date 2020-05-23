#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
const long long MAX = 1e17;
const int N = 100009;
int n, m, k, u, v, w;
struct heapData {
    int vir, dis;
};
struct adjData {
    int node, weight;
};
struct cmp {
    bool operator () (heapData a, heapData b) {
        return a.dis > b.dis;
    }
};
vector <vector <adjData> > adjList(N);
priority_queue <heapData, vector <heapData>, cmp> heap;
bool check[N];
long long d1[N], dn[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mpoints.inp", "r", stdin);
    freopen("mpoints.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        adjData x; x.node = v; x.weight = w;
        adjList[u].push_back(x);
    }
    heapData x; x.vir = 1; x.dis = 0;
    heap.push(x);
    fill(check + 1, check + n + 1, 0);
    fill(d1 + 1, d1 + n + 1, MAX);
    d1[1] = 0;
    while (heap.size()) {
        heapData closest = heap.top();
        heap.pop();
        check[closest.vir] = 1;
        for (int i = 0; i < adjList[closest.vir].size(); i++) {
            if (!check[adjList[closest.vir][i].node]) {
                if (d1[adjList[closest.vir][i].node] > d1[closest.vir] + adjList[closest.vir][i].weight) {
                    d1[adjList[closest.vir][i].node] = d1[closest.vir] + adjList[closest.vir][i].weight;
                    heapData z;
                    z.vir = adjList[closest.vir][i].node;
                    z.dis = d1[adjList[closest.vir][i].node];
                    heap.push(z);
                }
            }
        }
    }
    x.vir = n; x.dis = 0;
    heap.push(x);
    fill(check + 1, check + n + 1, 0);
    fill(dn + 1, dn + n + 1, MAX);
    dn[n] = 0;
    while (heap.size()) {
        heapData closest = heap.top();
        heap.pop();
        check[closest.vir] = 1;
        for (int i = 0; i < adjList[closest.vir].size(); i++) {
            if (!check[adjList[closest.vir][i].node]) {
                if (dn[adjList[closest.vir][i].node] > dn[closest.vir] + adjList[closest.vir][i].weight) {
                    dn[adjList[closest.vir][i].node] = dn[closest.vir] + adjList[closest.vir][i].weight;
                    heapData z;
                    z.vir = adjList[closest.vir][i].node;
                    z.dis = dn[adjList[closest.vir][i].node];
                    heap.push(z);
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        long long res = MAX;
        for (int j = 1; j <= n; j++) {
            if (d1[j] == MAX || dn[j] == MAX) continue;
            res = min(res, d1[j] * u + dn[j] * v);
        }
        cout << res << endl;
    }
    return 0;
}
