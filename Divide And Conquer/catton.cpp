// Bài này dùng chia để trị kết hợp với quy hoạch động
#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 1000000;
int d[40][40][60], n, m, k;
int cut(int r, int c, int k) {
    if (d[r][c][k] < MAX) return d[r][c][k];
    if (r * c == k || k == 0) return d[r][c][k] = 0;
    if (r * c < k) return d[r][c][k] = MAX;
    for (int i = 1; i < r; i++) {
        for (int x = 0; x <= k; x++) {
            d[r][c][k] = min(cut(i, c, x) + cut(r - i, c, k - x) + c * c, d[r][c][k]);
        }
    }
    for (int i = 1; i < c; i++) {
        for (int x = 0; x <= k; x++) {
            d[r][c][k] = min(cut(r, i, x) + cut(r, c - i, k - x) + r * r, d[r][c][k]);
        }
    }
    return d[r][c][k];
}
int main() {
    freopen("catton.inp", "r", stdin);
    freopen("catton.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int z = 0; z <= k; z++) d[i][j][z] = MAX;
        }
    }
    cout << cut(n, m, k);
}
