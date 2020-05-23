#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n, a[30], res = -1;
bool conf[30];
void backTrack(int k) {
    if (res != -1) return;
    for (int i = 0; i <= 1; i++) {
        conf[k] = i;
        if (k == n) {
            vector<int> b;
            for (int j = 1; j <= n; j++) if (!conf[j]) b.push_back(a[j]);
            bool ok = true;
            for (int u = 0; u < (int) b.size() - 1; u++) {
                for (int v = u + 1; v < b.size(); v++) {
                    if ((b[u] - b[v] == 1) || (b[u] - b[v] == 8) || (b[u] - b[v] == 9) || (b[v] - b[u] == 1) || (b[v] - b[u] == 8) || (b[v] - b[u] == 9)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                if (res != -1) return;
                res = b.size();
            }
        } else {
            backTrack(k + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    backTrack(1);
    cout << n - res;
    return 0;
}
