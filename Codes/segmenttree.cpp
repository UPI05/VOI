#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, x, st[100009];
void update(int id, int l, int r, int i, int v) {
    if (i > r || i < l) return;
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
    if (u > r || v < l) return -INF;
    if (u >= l && v <= r) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        update(1, 1, n, i, x);
    }
    cout << get(1, 1, n, 1, n);
    return 0;
}
