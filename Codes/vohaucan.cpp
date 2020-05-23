#include <iostream>
#include <fstream>
using namespace std;
int l, q, k, d, a[119];
int main() {
    cin >> l >> q >> k >> d;
    if (d > k) {
        cout << -1; return 0;
    }
    for (int i = 1; i <= l; i++) a[i] = 0;
    a[0] = q;
    int last;
    for (int i = d; i < l; i+=d) {
        last = i;
        a[i] = (a[i - d] / k) * (k - d);
        if (a[i - d] % k - d > 0) {
            a[i] += a[i - d] % k - d;
        }
    }
    int ans = (a[last] / k) * (k - (l - last)) + a[last] % k - (l - last);
    if (ans > 0) a[l] = ans;
    if (a[l] == 0) cout << -1;
    else cout << a[l];
    return 0;
}
