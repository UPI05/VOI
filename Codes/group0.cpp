#include <iostream>
#include <fstream>
using namespace std;
long long n, k, arr[60];
bool check(long long x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= x) sum += x;
        else sum += arr[i];
    }
    if (sum >= k * x) return 1;
    return 0;
}
int main() {
    freopen("group0.inp", "r", stdin);
    freopen("group0.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    long long l = 1, r = 50000000000, res;
    while (l <= r) {
        long long m = (l + r) / 2;
        if (check(m)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res;
    return 0;
}
