#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
const int MAX = 100000000;
int n, m, k, u, v, w;
char c[1009];
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
vector <vector <adjData> > adjList(10009);
priority_queue <heapData, vector <heapData>, cmp> heap;
bool check[1009];
int d[1009], resG = 0, resY = 0;
int main() {
    freopen("gyalpha.inp", "r", stdin);
    freopen("gyalpha.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adjData x; x.node = v;
        if (c[u] == c[v]) x.weight = 1;
        else x.weight = 4;
        adjList[u].push_back(x);
        x.node = u;
        adjList[v].push_back(x);
    }
    for (int u = 1; u <= n; u++) {
        heapData x; x.vir = u; x.dis = 0;
        heap.push(x);
        fill(check + 1, check + n + 1, 0);
        for (int i = 1; i <= n; i++) d[i] = MAX;
        d[u] = 0;
        while (heap.size()) {
            heapData closest = heap.top();
            heap.pop();
            check[closest.vir] = 1;
            for (int i = 0; i < adjList[closest.vir].size(); i++) {
                if (!check[adjList[closest.vir][i].node]) {
                    int s;
                    if (c[adjList[closest.vir][i].node] == c[u]) s = 1;
                    else s = 4;
                    if (d[adjList[closest.vir][i].node] > d[closest.vir] + s) {
                        d[adjList[closest.vir][i].node] = d[closest.vir] + s;
                        heapData z;
                        z.vir = adjList[closest.vir][i].node;
                        z.dis = d[adjList[closest.vir][i].node];
                        heap.push(z);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (c[u] == 'Y' && c[i] == 'Y') resY += d[i];
            else if (c[u] == 'G' && c[i] == 'G') resG += d[i];
        }
    }
    cout << resG / 2 << " " << resY / 2;
    return 0;
}
