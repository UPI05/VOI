#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, k, a[500009], ST[1000009];
char c;
vector<int> pos[10];
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
    freopen("kek.inp", "r", stdin);
    freopen("kek.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> c;
        a[i] = c - '0';
        update(1, 1, n, i, a[i]);
        pos[a[i]].push_back(i);
    }
    k = n - k;
    int last = 0;
    for (int i = 1; i <= k; i++) {
        int l = last + 1, r = n - (k - i);
        int Max = get(1, 1, n, l, r);
        int u = 0, v = (int) pos[Max].size() - 1, ans;
        while (u <= v) {
            int mid = (u + v) / 2;
            if (pos[Max][mid] >= l && pos[Max][mid] <= r) {
                ans = mid;
                v = mid - 1;
            } else {
                if (pos[Max][mid] < l) {
                    u = mid + 1;
                } else if (pos[Max][mid] > r) {
                    v = mid - 1;
                }
            }
        }
        last = pos[Max][ans];
        cout << a[last];
    }
    return 0;
}
