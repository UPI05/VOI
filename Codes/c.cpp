#include <bits/stdc++.h>
using namespace std;
int n;
struct dt {
    int fi, se, th;
} a[100009];
vector<int> res, pos[100009];
int main() {
    //freopen("c.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n - 1; i++) {
        cin >> a[i].fi >> a[i].se >> a[i].th;
        pos[a[i].fi].push_back(i); pos[a[i].se].push_back(i); pos[a[i].th].push_back(i);
    }
    int firPos, firNum;
    for (int i = 1; i <= n; i++) if (pos[i].size() == 1) firPos = pos[i][0], firNum = i;
    int x = a[firPos].fi, y = a[firPos].se;
    if (x == firNum) x = a[firPos].th;
    if (y == firNum) y = a[firPos].th;
    res.push_back(firNum);
    int p;
    for (int i = 0; i < pos[x].size(); i++) {
        for (int j = 0; j < pos[y].size(); j++) {
            if (pos[x][i] == pos[y][j]) {
                if (pos[x][i] == firPos) continue;
                p = pos[x][i];
                goto out;
            }
        }
    }
    out:
    int k;
    if (a[p].fi != x && a[p].fi != y) k = a[p].fi;
    if (a[p].se != x && a[p].se != y) k = a[p].se;
    if (a[p].th != x && a[p].th != y) k = a[p].th;
    int p2 = -1;
    for (int i = 0; i < pos[x].size(); i++) {
        for (int j = 0; j < pos[k].size(); j++) {
            if (pos[x][i] == pos[k][j]) {
                if (pos[x][i] == p) continue;
                p2 = pos[x][i];
                goto out2;
            }
        }
    }
    out2:
    if (p2 != -1) {
        res.push_back(y);
        y = k;
    } else {
        res.push_back(x);
        x = y;
        y = k;
    }
    while (res.size() != n - 2) {
        for (int i = 0; i < pos[x].size(); i++) {
            for (int j = 0; j < pos[k].size(); j++) {
                if (pos[x][i] == pos[k][j]) {
                    if (pos[x][i] == p) continue;
                    p2 = pos[x][i];
                    goto out3;
                }
            }
        }
        out3:
        p = p2;
        res.push_back(x);
        if (a[p2].fi != x && a[p2].fi != y) k = a[p2].fi;
        if (a[p2].se != x && a[p2].se != y) k = a[p2].se;
        if (a[p2].th != x && a[p2].th != y) k = a[p2].th;
        x = y; y = k;
    }
    res.push_back(x), res.push_back(y);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}
