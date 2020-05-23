/*
** @author: kasper08
** @date: /08/2019
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<int> ve;
typedef vector<ve > ve2;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define foru(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define DEBUG 1
int n, m, c[100009], p[100009][100], check[100009], h[100009], x, y, u, v;
ve2 adjList(100009);
void dfs(int u) {
    check[u] = 1;
    foru(i, 0, (int) adjList[u].size() - 1) {
        if (!check[adjList[u][i]]) {
            h[adjList[u][i]] = h[u] + 1;
            c[adjList[u][i]] = u;
            dfs(adjList[u][i]);
        }
    }
}
int main() {
#if DEBUG
    freopen("sample.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    foru(i, 1, m) {
        cin >> u >> v;
        adjList[u].pb(v);
    }
    for (int i = 1; (1 << i) <= n; i++) {
        foru(j, 1, n) {
            p[j][i] = -1;
        }
    }
    foru(i, 1, n) p[i][0] = c[i];
    for (int i = 1; (1 << i) <= n; i++) {
        foru(j, 1, n) {
            if (p[j][i - 1] != -1)
                p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
    foru(i, 1, n) check[i] = 0;
    c[1] = 0;
    h[1] = 1;
    dfs(1);
    if (h[x] < h[y]) {
        swap(x, y);
    }
    int l = log2(h[x]);
    ford(i, l, 0) {
        if (1 << i && (h[x] - h[y]) > 0) {
            x = p[x][i];
        }
    }
    ford(i, l, 0) {
        if (p[x][i] != -1 && p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    cout << c[x];
    return 0;
}
