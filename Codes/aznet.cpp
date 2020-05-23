#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
const int NMAX = 19;
int t, n, m, u, v, c, res, a[NMAX], b[NMAX], conf[NMAX], pos[NMAX][NMAX];
bool check[NMAX];
pair<bool, int> adj[NMAX][NMAX];
vector<pair<int, int> > ans;
void backTrack(int k) {
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = 1;
        } else continue;
        conf[k] = i;
        if (k == n) {
            bool ok = true;
            for (int i = 2; i <= n; i++) {
                bool ok2 = false;
                for (int j = 1; j < i; j++) {
                    if (adj[conf[i]][conf[j]].first) {
                        ok2 = true;
                        break;
                    }
                }
                if (!ok2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                vector<pair<int, int> > path;
                int countA = 0, countB = 0;
                for (int i = n; i > 1; i--) {
                    for (int j = i - 1; j >= 1; j--) {
                        if (adj[conf[i]][conf[j]].first) {
                            path.push_back(make_pair(conf[i], conf[j]));
                            if (adj[conf[i]][conf[j]].second == 1) {
                                ++countA;
                            } else ++countB;
                            break;
                        }
                    }
                }
                int pathAns = a[countA] + b[countB];
                if (pathAns < res) {
                    res = pathAns;
                    ans = path;
                }
            }
        } else {
            backTrack(k + 1);
        }
        check[i] = 0;
    }
}
int main() {
    //freopen("aznet.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        res = 1000000009;
        a[0] = 0; b[0] = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) adj[i][j].first = 0;
        }
        for (int i = 1; i < n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) cin >> b[i];
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> c;
            pos[u][v] = i;
            pos[v][u] = i;
            adj[u][v].first = adj[v][u].first = 1;
            adj[u][v].second = adj[v][u].second = c;
        }
        for (int i = 1; i <= n; i++) check[i] = 0;
        backTrack(1);
        for (int i = 0; i < ans.size(); i++) cout << pos[ans[i].first][ans[i].second] << " "; cout << endl;
    }
    return 0;
}
