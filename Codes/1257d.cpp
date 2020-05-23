#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 9, INF = 2e9;
int t, n, m, a[NMAX], pMax[NMAX], ST[NMAX];
pair<int, int> b[NMAX];
void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        return ;
    }
    if (l == r) {
        ST[id] = v;
        return ;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -INF;
    }
    if (u <= l && r <= v) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}
int main() {
    //freopen("1257d.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            update(1, 1, n, i, a[i]);
        }
        cin >> m;
        int sMax = 0, pM = 0;
        for (int i = 1; i <= m; i++) {
            cin >> b[i].first >> b[i].second;
            sMax = max(sMax, b[i].second);
            pM = max(pM, b[i].first);
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] > pM) {
                cout << -1 << endl;
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        for (int i = 1; i <= sMax; i++) pMax[i] = 0;
        for (int i = 1; i <= m; i++) {
            pMax[b[i].second] = max(pMax[b[i].second], b[i].first);
        }
        for (int i = sMax - 1; i > 0; i--) {
            if (pMax[i] == 0) pMax[i] = pMax[i + 1];
            else {
                pMax[i] = max(pMax[i], pMax[i + 1]);
            }
        }
        int pos = 1, res = 0;
        while (pos <= n) {
            res++;
            int l = 1, r = sMax, ans;
            while (l <= r) {
                int mid = (l + r) / 2;
                int k = get(1, 1, n, pos, pos + mid - 1);
                if (pMax[mid] >= k) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            pos += ans;
        }
        cout << res << endl;
    }
    return 0;
}
