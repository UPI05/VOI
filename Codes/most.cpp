#include <bits/stdc++.h>
using namespace std;
int n, a[100009], p[100009];
long long res = 0;
struct dt {
    int u, v, w;
};
vector<dt> edges;
int root(int k) {
    if (p[k] == k) return k;
    p[k] = root(p[k]);
    return p[k];
}
void connect(int u, int v, int id) {
    u = root(u); v = root(v);
    if (u != v) {
        p[u] = v;
        res += edges[id].w;
    }
}
bool cmp(dt a, dt b) {
    return a.w < b.w;
}
int main() {
    //freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dt x;
            x.u = i, x.v = j, x.w = a[i] % a[j];
            edges.push_back(x);
            x.u = j, x.v = i, x.w = a[j] % a[i];
            edges.push_back(x);
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i].u, edges[i].v, i);
    }
    cout << res;
    return 0;
}
