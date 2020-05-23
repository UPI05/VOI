#include <iostream>
#include <fstream>
#include <utility>
using namespace std;
int n, w;
long long f[109][100009];
pair<int, int> p[109];
int main() {
    freopen("knapsack1.inp", "r", stdin);
    //freopen("knapsack1.out", "w", stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    for (int i = 1; i <= w; i++) {
        if (i >= p[1].first) f[1][i] = p[1].second;
        else f[1][i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (p[i].first > j) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - p[i].first] + p[i].second);
        }
    }
    cout << f[n][w];
    return 0;
}
