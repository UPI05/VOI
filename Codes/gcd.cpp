#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, k, a, st[100009];
void update(int id, int l, int r, int i, int v) {
    if (i < l || i > r) return;
    if (l == r) {
        st[i] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return -1;
    if (l >= u && v >= r) return st[id];
    int mid = (l + r) / 2;
    int a = get(id * 2, l, mid, u, v), b = get(id * 2 + 1, mid + 1, r, u, v);
    if (a == -1) return b;
    if (b == -1) return a;
    return __gcd(a, b);
}
int main() {
    freopen("gcd.inp", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(1, 1, n, i, a);
    }
    for (int i = 1; i <= n * 2; i++) cout << st[i] << endl;
    //cout << get(1, 1, n, 1, 1);
    return 0;
}
