// Gọi f[i] là độ dài dãy con tăng dài nhất khi chọn arr[i] làm phần tử cuối cùng.
#include <iostream>
#include <fstream>
using namespace std;
const int NMAX = 1009;
int n, arr[NMAX], f[NMAX], res = 1, trace[NMAX];
void printNum(int pos) {
    if (pos == 0) return;
    printNum(trace[pos]);
    cout << arr[pos] << " ";
}
int main() {
    freopen("liq.inp", "r", stdin);
    //freopen("liq.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) f[i] = 1, trace[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] > arr[i]) {
                if (f[i] + 1 > f[j]) {
                    f[j] = f[i] + 1;
                    trace[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] > f[res]) res = i;
    }
    cout << f[res] << endl;
    printNum(res);
    return 0;
}
