#include <iostream>
#include <fstream>
using namespace std;
int n, m, maxSize = 0, res = 0, Size;
char c;
bool matrix[400][400];
void dfs(int x, int y) {
    matrix[x][y] = 1;
    Size++;
    if (x + 1 <= 3 * n && !matrix[x + 1][y]) dfs(x + 1, y);
    if (x - 1 > 0 && !matrix[x - 1][y]) dfs(x - 1, y);
    if (y + 1 <= 3 * m && !matrix[x][y + 1]) dfs(x, y + 1);
    if (y - 1 > 0 && !matrix[x][y - 1]) dfs(x, y - 1);
    //if (x + 1 <= 3 * n && y + 1 <= 3 * m && !matrix[x + 1][y + 1]) dfs(x + 1, y + 1);
    //if (x - 1 > 0 && y - 1 > 0 && !matrix[x - 1][y - 1]) dfs(x - 1, y - 1);
    //if (x - 1 > 0 && y + 1 <= 3 * m && !matrix[x - 1][y + 1]) dfs(x - 1, y + 1);
    //if (x + 1 <= 3 * n && y - 1 > 0 && !matrix[x + 1][y - 1]) dfs(x + 1, y - 1);
}
int main() {
    freopen("beca.inp", "r", stdin);
    freopen("beca.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; i++) {
        for (int j = 1; j <= 3 * m; j++) matrix[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '\\') {
                matrix[(i - 1) * 3 + 1][(j - 1) * 3 + 1] = 1;
                matrix[(i - 1) * 3 + 2][(j - 1) * 3 + 2] = 1;
                matrix[(i - 1) * 3 + 3][(j - 1) * 3 + 3] = 1;
            } else {
                matrix[(i - 1) * 3 + 1][(j - 1) * 3 + 3] = 1;
                matrix[(i - 1) * 3 + 2][(j - 1) * 3 + 2] = 1;
                matrix[(i - 1) * 3 + 3][(j - 1) * 3 + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= 3 * n; i++) {
        if (!matrix[i][1]) dfs(i, 1);
        if (!matrix[i][3 * m]) dfs(i, 3 * m);
    }
    for (int i = 1; i <= 3 * m; i++) {
        if (!matrix[1][i]) dfs(1, i);
        if (!matrix[3 * n][i]) dfs(3 * n, i);
    }
    for (int i = 1; i <= 3 * n; i++) {
        for (int j = 1; j <= 3 * m; j++) {
            if (!matrix[i][j]) {
                Size = 0;
                dfs(i, j);
                maxSize = max(maxSize, Size);
                res++;
            }
        }
    }
    cout << res << endl;
    cout << maxSize / 6<< endl;
    return 0;
}
