#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 100000000;
int n, m, s, t, u, v, w, matrix[109][109], d[109], trace[109];
bool check[109];
void dijkstra() {
    for (int i = 1; i <= n; i++) {
        int pos = -1;
        for (int j = 1; j <= n; j++) {
            if (!check[j] && pos == -1) pos = j;
            else if (!check[j] && pos != -1) if (d[j] < d[pos]) pos = j;
        }
        check[pos] = 1;
        if (pos != -1) {
            for (int j = 1; j <= n; j++) {
            if (!check[j] && matrix[pos][j] != 0) {
                if (d[j] > d[pos] + matrix[j][pos]) {
                    d[j] = d[pos] + matrix[j][pos];
                    trace[j] = pos;
                }
            }
        }
        }
    }
}
void Trace(int t) {
    if (trace[t] == 0) return;
    else {
        Trace(trace[t]);
        cout << trace[t] << " ";
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        d[i] = MAX; check[i] = 0; trace[i] = 0;
        for (int j = 1; j <= n; j++) matrix[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        matrix[u][v] = w; matrix[v][u] = w;
    }
    d[s] = 0;
    dijkstra();
    for (int i = 1; i <= k; i++) {
        cin >> w >> u >> v;
        if (w == 0) cout <<
    }
    cout << d[t] << endl;
    Trace(t);
    cout << t;
    return 0;
}
