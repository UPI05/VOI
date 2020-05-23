#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, k, arr[1009];
int binSearch(int k, int l, int r) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] > k) {
            r = m - 1;
        } else if (arr[m] < k) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}
int main() {
    freopen("binarysearch.inp", "r", stdin);
    freopen("binarysearch.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    cout << binSearch(k, 1, n);
    return 0;
}
