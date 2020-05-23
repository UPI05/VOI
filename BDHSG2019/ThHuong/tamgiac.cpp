#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n, f[1009], trace[1009];
struct dt {
    int x1, x2, x3, y1, y2, y3;
} geo[1009];
long long getP(long long xA, long long yA, long long xB, long long yB, long long xP, long long yP) {
    xB -= xA; yB -= yA; xP -= xA; yP -= yA;
    return (xB * yP - yB * xP);
}
bool getPos(dt a, int x, int y) {
    long long i = getP(a.x1, a.y1, a.x2, a.y2, x, y);
    long long j = getP(a.x2, a.y2, a.x3, a.y3, x, y);
    long long z = getP(a.x3, a.y3, a.x1, a.y1, x, y);
    if ((i >= 0 && j >= 0 && z >= 0) || (i <= 0 && j <= 0 && z <= 0)) return 1;
    return 0;
}
bool checkGeo(dt a, dt b) {
    if (getPos(a, b.x1, b.y1) && getPos(a, b.x2, b.y2) && getPos(a, b.x3, b.y3)) return 1;
    return 0;
}
void pr(int k) {
    if (trace[k] == 0) {
            cout << k << " ";
        return;
    }
    pr(trace[k]);
    cout << k << " ";
}
int main() {
    freopen("tamgiac.inp", "r", stdin);
    freopen("tamgiac.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> geo[i].x1 >> geo[i].y1 >> geo[i].x2 >> geo[i].y2 >> geo[i].x3 >> geo[i].y3;
    f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = 1, trace[i] = 0;
    trace[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (checkGeo(geo[j], geo[i])) {
                if (f[i] + 1 > f[j]) {
                    f[j] = f[i] + 1;
                    trace[j] = i;
                }
            }
        }
    }
    int p = 1;
    for (int i = 2; i <= n; i++) if (f[i] > f[p]) {
        p = i;
    }
    cout << f[p] << endl;
    pr(p);
    return 0;
}
