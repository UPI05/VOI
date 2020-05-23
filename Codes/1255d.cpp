#include <bits/stdc++.h>
using namespace std;
int t, r, c, k, cha, ricNum, x, y, cnt;
char ma[109][109], pres[] = {'F','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E'
,'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
bool check[109][109], ok;
void dfs(int u, int v) {
    if (cnt == ricNum) {
        if (!ok) {
            x = u, y = v;
            ok = 1;
        }
        return;
    }
    check[u][v] = 1;
    cnt += (ma[u][v] == 'R');
    ma[u][v] = pres[cha];
    if ((v - 1 > 0) && !check[u][v - 1]) dfs(u, v - 1);
    if ((u - 1 > 0) && !check[u - 1][v]) dfs(u - 1, v);
    if ((u + 1 <= r) && !check[u + 1][v]) dfs(u + 1, v);
    if ((v + 1 <= c) && !check[u][v + 1]) dfs(u, v + 1);
}
void dfs2(int u, int v) {
    check[u][v] = 1;
    ma[u][v] = pres[cha];
    if ((v - 1 > 0) && !check[u][v - 1]) dfs2(u, v - 1);
    if ((u - 1 > 0) && !check[u - 1][v]) dfs2(u - 1, v);
    if ((u + 1 <= r) && !check[u + 1][v]) dfs2(u + 1, v);
    if ((v + 1 <= c) && !check[u][v + 1]) dfs2(u, v + 1);
}
int main() {
    //freopen("1255d.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> r >> c >> k;
        int rice = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> ma[i][j];
                if (ma[i][j] == 'R') rice++;
                check[i][j] = 0;
            }
        }
        x = 1, y = 1;
        ricNum = rice / k + 1;
        cha = 0;
        for (int i = 1; i <= rice % k; i++) {
            cnt = 0;
            ok = 0;
            cha++;
            dfs(x, y);
        }
        ricNum--;
        for (int i = 1; i <= (k - (rice % k)); i++) {
            cnt = 0;
            ok = 0;
            cha++;
            dfs(x, y);
        }
        dfs2(x, y);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) cout << ma[i][j]; cout << endl;
        }
    }
    return 0;
}
