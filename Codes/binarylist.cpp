#include <iostream>
#include <fstream>
using namespace std;
int n, m, x, pos = 1;
bool ans[10009], ko = true;
bool ok() {
    for (int i = 1; i <= n - m + 1; i++) {
        bool o = true;
        for (int j = i; j <= i + m - 1; j++) {
            if (ans[j] == 1) {
                o = false;
                break;
            }
        }
        if (o) return 0;
    }
    return 1;
}
void backTrack(int k) {
    for (int i = 0; i <= 1; i++) {
        ans[k] = i;
        if (k == n) {
            if (ok()) {
                if (pos == x) {
                    ko = false;
                    for (int j = 1; j <= n; j++) cout << ans[j] << " ";
                    pos++;
                    return;
                }
                pos++;
            }
        } else {
            backTrack(k + 1);
        }
    }
}
int main() {
    cin >> n >> x >> m;
    backTrack(1);
    if (ko) cout << -1;
    return 0;
}
