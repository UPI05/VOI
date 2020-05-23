#include <iostream>
#include <fstream>
using namespace std;
int q, u, v, c, p[1009];
int root(int k) {
    if (p[k] == k) return k;
    p[k] = root(p[k]);
    return p[k];
}
void connect(int u, int v) {
    u = root(u); v = root(v);
    if (u != v) {
        p[u] = v;
    }
}
int main() {
    cin >> q;
    for (int i = 1; i <= 1000; i++) p[i] = i;
    while (q--) {
        cin >> u >> v >> c;
        if (c == 0) {
            if (root(u) == root(v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            connect(u, v);
        }
    }
    return 0;
}
