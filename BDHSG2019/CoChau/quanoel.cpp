#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, m, x, y, h[109][109];
char c[109][109];
bool check[109][109];
vector<int> height;
unordered_map<int, int> umap;
vector<pair<int, int> > houses;
int l, r;
void dfs(int x, int y) {
    check[x][y] = 1;
    if (x + 1 <= n && h[x + 1][y] <= height[r] && h[x + 1][y] >= height[l] && !check[x + 1][y]) dfs(x + 1, y);
    if (x - 1 >= 1 && h[x - 1][y] <= height[r] && h[x - 1][y] >= height[l] && !check[x - 1][y]) dfs(x - 1, y);
    if (y + 1 <= m && h[x][y + 1] <= height[r] && h[x][y + 1] >= height[l] && !check[x][y + 1]) dfs(x, y + 1);
    if (y - 1 >= 1 && h[x][y - 1] <= height[r] && h[x][y - 1] >= height[l] && !check[x][y - 1]) dfs(x, y - 1);
    if (x + 1 <= n && y + 1 <= m && h[x + 1][y + 1] <= height[r] && h[x + 1][y + 1] >= height[l] && !check[x + 1][y + 1]) dfs(x + 1, y + 1);
    if (x - 1 >= 1 && y + 1 <= m && h[x - 1][y + 1] <= height[r] && h[x - 1][y + 1] >= height[l] && !check[x - 1][y + 1]) dfs(x - 1, y + 1);
    if (x - 1 >= 1 && y - 1 >= 1 && h[x - 1][y - 1] <= height[r] && h[x - 1][y - 1] >= height[l] && !check[x - 1][y - 1]) dfs(x - 1, y - 1);
    if (x + 1 <= n && y - 1 >= 1 && h[x + 1][y - 1] <= height[r] && h[x + 1][y - 1] >= height[l] && !check[x + 1][y - 1]) dfs(x + 1, y - 1);
}
int main() {
    //freopen("c11post.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'P') {
                x = i; y = j;
            }
            if (c[i][j] == 'K') houses.push_back(make_pair(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            umap[h[i][j]]++;
            if (umap[h[i][j]] == 1) height.push_back(h[i][j]);
        }
    }
    sort(height.begin(), height.end());
    l = 0, r = height.size() - 1;
    bool ok;
    do {
        r--;
        if (h[x][y] <= height[r] && h[x][y] >= height[l]) ok = true;
        else ok = false;
        if (ok)
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) check[i][j] = 0;
            }
            dfs(x, y);
            for (int i = 0; i < houses.size(); i++) if (!check[houses[i].first][houses[i].second]) {
                ok = false;
                break;
            }
    } while (ok);
    r++;
    do {
        l++;
        if (h[x][y] >= height[l] && h[x][y] <= height[r]) ok = true;
        else ok = false;
        if (ok) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) check[i][j] = 0;
            }
            dfs(x, y);
            for (int i = 0; i < houses.size(); i++) if (!check[houses[i].first][houses[i].second]) {
                ok = false;
                break;
            }
        }
    } while (ok);
    l--;
    cout << height[r] - height[l];
    return 0;
}
