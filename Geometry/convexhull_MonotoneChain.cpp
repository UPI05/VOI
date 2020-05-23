// Xét 3 điểm A(xA, yA), B(xB, yB) và O(0, 0). Ta có cross product: Nếu xA*yB - yA*xB > 0 thì O-->A-->B quẹo trái, < 0 thì quẹo phải, = 0 thì
// O, A, B thẳng hàng. Tổng quát hơn: Với 3 điểm P, A, B, ta đưa về hệ trục với gốc tọa độ tại P và làm tương tự.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int t, n;
pair<int, int> points[10009];
vector<pair<int, int> > up, down;
long long getDirect(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    return ((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
}
int main() {
    //freopen("convexhull.inp", "r", stdin);
    //freopen("convexhull.out", "w", stdout);
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        sort(points + 1, points + n + 1);
        pair<int, int> p1 = points[1], p2 = points[n];
        up.clear(); down.clear();
        up.push_back(p1); down.push_back(p1);
        for (int i = 2; i <= n; i++) {
            if (i == n || getDirect(p1, points[i], p2) < 0) {
                while (up.size() >= 2 && getDirect(up[up.size() - 2], up[up.size() - 1], points[i]) >= 0) up.pop_back();
                up.push_back(points[i]);
            }
            if (i == n || getDirect(p1, points[i], p2) > 0) {
                while (down.size() >= 2 && getDirect(down[down.size() - 2], down[down.size() - 1], points[i]) <= 0) down.pop_back();
                down.push_back(points[i]);
            }
        }
        vector<pair<int, int> > res;
        for (int i = 0; i < up.size(); i++) res.push_back(up[i]);
        for (int i = down.size() - 2; i > 0; i--) res.push_back(down[i]);
        //
        int pos;
        for (int i = 0; i < res.size(); i++) if (res[i].first == points[1].first && res[i].second == points[1].second) pos = i;
        cout << "Case #" << tc << endl;
        for (int i = pos; i >= 0; i--) cout << res[i].first << " " << res[i].second << endl;
        for (int i = res.size() - 1; i > pos; i--) cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
