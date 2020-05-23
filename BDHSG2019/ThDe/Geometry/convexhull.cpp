#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
pair<int, int> arr[100009];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second < b.second || (a.second == b.second && a.first < b.first));
}
long long getDirect(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    return ((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
}
vector<pair<int, int> > leftArr, rightArr;
int main() {
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr + 1, arr + n + 1, cmp);
    pair<int, int> p1 = arr[1], p2 = arr[n];
    leftArr.push_back(p1); rightArr.push_back(p1);
    for (int i = 2; i <= n; i++) {
        if (i == n || getDirect(p1, arr[i], p2) < 0) {
            while (leftArr.size() >= 2 && getDirect(leftArr[leftArr.size() - 2], leftArr[leftArr.size() - 1], arr[i]) >= 0) leftArr.pop_back();
            leftArr.push_back(arr[i]);
        }
        if (i == n || getDirect(p1, arr[i], p2) > 0) {
            while (rightArr.size() >= 2 && getDirect(rightArr[rightArr.size() - 2], rightArr[rightArr.size() - 1], arr[i]) <= 0) rightArr.pop_back();
            rightArr.push_back(arr[i]);
        }
    }
    vector<pair<long long, long long> > res;
    for (int i = 0; i < rightArr.size(); i++) res.push_back(rightArr[i]);
    for (int i = leftArr.size() - 2; i > 0; i--) res.push_back(leftArr[i]);
    cout << res.size() << endl;
    long long ans = 0;
    for (int i = 1; i < res.size(); i++) ans += (res[i - 1].first * res[i].second - res[i - 1].second * res[i].first);
    ans += (res[res.size() - 1].first * res[0].second - res[res.size() - 1].second * res[0].first);
    ans = abs(ans);
    cout << ans / 2 << "." << ((ans % 2)? 5 : 0) << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i].first << " " << res[i].second << endl;
    return 0;
}
