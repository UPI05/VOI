// Quay lui sinh xâu nhị phân độ dài n -- Ứng dụng quay lui chọn n phần tử: a[i] = 1 thì chọn phần tử thứ i, a[i] = 0 thì không chọn phần tử thứ i.
#include <iostream>
#include <fstream>
using namespace std;
int n, a[30];
void backTrack(int k) {
    for (int i = 0; i <= 1; i++) {
        a[k] = i;
        if (k == n) {
            for (int j = 1; j <= n; j++) cout << a[j]; cout << endl;
        } else {
            backTrack(k + 1);
        }
    }
}
int main() {
    freopen("backtracking.inp", "r", stdin);
    freopen("backtracking.out", "w", stdout);
    cin >> n;
    backTrack(1);
    return 0;
}
