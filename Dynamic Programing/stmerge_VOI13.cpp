#include <iostream>
#include <fstream>
using namespace std;
int t, n, m, arr[1009][1009];
long long f[1009][1009][2];
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
                f[i][j][0] = f[i][j][1] = 0;
            }
        }
        f[1][1][0] = f[1][1][1] = arr[1][1];
        for (int i = 2; i <= n; i++) {
            f[i][1][0] = min(f[i - 1][1][0], f[i - 1][1][1] + arr[i][1]);
            f[i][1][1] = arr[i][1];
        }
        for (int i = 2; i <= m; i++) {
            f[1][i][0] = arr[1][i];
            f[1][i][1] = min(f[1][i - 1][1], f[1][i - 1][0] + arr[1][i]);
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1] + arr[i][j]);
                f[i][j][1] = min(f[i][j - 1][0] + arr[i][j], f[i][j - 1][1]);
            }
        }
        cout << min(f[n][m][0], f[n][m][1]) << endl;
    }
    return 0;
}
