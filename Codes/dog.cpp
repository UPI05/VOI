#include <iostream>
#include <fstream>
using namespace std;
int n, u, v, t, f, w[1009];
int res[1009], d[1009], ans[1009];
int main() {
    //freopen("dog.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    cin >> f;
    for (int i = 1; i <= f; i++) {
        cin >> u >> v;
        d[u] = v;
    }
    cin >> t;
    for (int i = 1; i <= n; i++) res[i] = 0;
    for (int i = 0; i <= t; i++) ans[i] = -1;
    ans[0] = 1;
    for (int i = 0; i <= t; i++) {
        if (ans[i] != -1) {
            res[ans[i]]++;
            ans[i + w[d[ans[i]]]] = d[ans[i]];
        }
    }
    for (int i = 1; i <= n; i++) cout << res[i] << endl;
    return 0;
}
