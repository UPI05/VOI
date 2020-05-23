#include <iostream>
#include <fstream>
using namespace std;
int n, m, res = 0, u, v;
bool matrix[20][20];
int val[20];
void backTrack(int k) {
    for (int i = 1; i <= 3; i++) {
        val[k] = i;
        if (k == n) {
            bool ok = true;
            for (int j = 1; j < n; j++) {
                if (!ok) break;
                for (int z = j + 1; z <= n; z++) {
                    if (matrix[j][z]) {
                        if ((val[j] + val[z]) % 2 == 0) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (ok) res++;
        } else {
            backTrack(k + 1);
        }
    }
}
int main() {
    //freopen("bgraph.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) matrix[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        matrix[u][v] = matrix[v][u] = 1;
    }
    backTrack(1);
    cout << res;
    return 0;
}
