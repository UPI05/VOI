#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int n, k;
long double a[100009], sum[100009], res = 0;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = i + k - 1; j <= n; j++) {
            res = max(res, (sum[j] - sum[i - 1]) / (j - i + 1));
        }
    }
    cout << setprecision(5) << fixed << res << endl;
    return 0;
}
