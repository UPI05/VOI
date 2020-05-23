#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int k, n, a[1009];
int main() {
    freopen("a.inp", "r", stdin);
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, min(a[i], n - i + 1));
        }
        cout << res << endl;
    }
    return 0;
}
