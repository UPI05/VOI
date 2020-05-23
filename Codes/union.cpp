#include <iostream>
#include <fstream>
#include <ctime>
#include <unordered_map>
#include <vector>
using namespace std;
long long n, x, node[300009];
int Max = 0;
vector<long long> node2[300009];
int main() {
    freopen("union.inp", "r", stdin);
    //freopen("union.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (x != 1) {
            node2[i].push_back(x);
            x /= 2;
        }
        node2[i].push_back(1);
        Max = max(Max, (int) node2[i].size());
    }
    bool ok = true;
    while (Max--) {
        if (ok) {
            for (int i = 1; i <= n; i++) node2[i].pop_back();
        }
        int lca = node2[1].back();
        for (int i = 1; i <= n; i++) {
            if (node2[i].back() != lca) {
                ok = false;
                break;
            }
        }
    }
    unordered_map<long long, bool> umap;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < node2[i].size(); j++) {
            if (!umap[node2[i][j]]) {
                umap[node2[i][j]] = 1;
                res++;
            }
        }
    }
    cout << res;
    cerr<<"time: " << clock();
        return 0;
}
