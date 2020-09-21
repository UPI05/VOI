#include <bits/stdc++.h>
using namespace std;
int n, x, st[10009];
const int INF = 1e9;
void update(int id, int l, int r, int i, int v) {
    if (i > r || i < l) {
        return;
    }
    if (l == r) {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return -INF;
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        update(1, 1, n, i, x);
    }
    cout << get(1, 1, n, 3, 6);
    return 0;
}
