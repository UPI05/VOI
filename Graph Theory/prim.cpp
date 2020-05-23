#include <iostream>
#include <fstream>
using namespace std;
const int NMAX = 1009;
int n, m, u, v, w, arr[NMAX][NMAX], d[NMAX], trace[NMAX];
bool check[NMAX];
void prim() {
    int c = n - 1;
    while (c--) {
        int Min = NMAX + 1;
        int node = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] < Min && !check[i]) {
                Min = d[i];
                node = i;
            }
        }
        check[node] = 1;
        for (int i = 1; i <= n; i++) {
            if (arr[i][node] && d[i] > arr[i][node]) {
                d[i] = arr[i][node]; trace[i] = node;
            }
        }
    }
}
int main() {
    freopen("prim.inp", "r", stdin);
    freopen("prim.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        check[i] = 0;
        d[i] = NMAX;
        trace[i] = 0;
        for (int j = 1; j <= n; j++) arr[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }
    check[1] = 1;
    d[1] = 0;
    prim();
    return 0;
}
