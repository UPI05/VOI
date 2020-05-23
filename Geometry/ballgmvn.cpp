#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;
pair<double, double> a[2009];
struct dt {
    double x, y;
    int pos;
} b[1009];
int main() {
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++) {
        vector<pair<double, int> > ans;
        for (int j = n + 1; j <= 2 * n; j++) {
            b[j - n].x = a[j].first - a[i].first;
            b[j - n].y = a[j].second - a[i].second;
        }
        for (int j = 1; j <= n; j++) ans.push_back(make_pair(b[j].x / b[j].y, j + n));
        sort(ans.begin(), ans.end());
        for (int j = 0; j < (int) ans.size() - 1; j++) {
            if (ans[j].first == ans[j + 1].first) {
                cout << i << " " << ans[j].second << " " << ans[j + 1].second << endl;
                return 0;
            }
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        vector<pair<double, int> > ans;
        for (int j = 1; j <= n; j++) {
            b[j].x = a[j].first - a[i].first;
            b[j].y = a[j].second - a[i].second;
        }
        for (int j = 1; j <= n; j++) ans.push_back(make_pair(b[j].x / b[j].y, j));
        sort(ans.begin(), ans.end());
        for (int j = 0; j < (int) ans.size() - 1; j++) {
            if (ans[j].first == ans[j + 1].first) {
                cout << i << " " << ans[j].second << " " << ans[j + 1].second << endl;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
