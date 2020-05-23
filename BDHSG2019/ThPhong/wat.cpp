#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int N = 1e5 + 9;
int n, q, x, u, v, Count[30];
string s;
char node[N];
bool check[N];
vector<int> ans[N], adj[N];
void dfs(int k) {
    check[k] = 1;
    if (adj[k].size() == 1 && k != 1) {
        ans[k][node[k] - 'a' + 1]++;
        return;
    }
    for (int i = 0; i < adj[k].size(); i++) {
        if (!check[adj[k][i]]) {
            dfs(adj[k][i]);
            for (int j = 1; j <= 26; j++) ans[k][j] += ans[adj[k][i]][j];
        }
    }
    ans[k][node[k] - 'a' + 1]++;
}
int main() {
    freopen("wat.inp", "r", stdin);
    freopen("wat.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> node[i];
        check[i] = 0;
        for (int j = 0; j <= 26; j++) ans[i].push_back(0);
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        cin >> x >> s;
        for (int i = 1; i <= 26; i++) Count[i] = 0;
        for (int i = 0; i < s.length(); i++) Count[s[i] - 'a' + 1]++;
        int res = 0;
        for (int i = 1; i <= 26; i++) {
            if (Count[i] > ans[x][i]) res += (Count[i] - ans[x][i]);
        }
        cout << res << endl;
    }

    return 0;
}
