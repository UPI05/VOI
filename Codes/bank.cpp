#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;
int n, t, res = 0;
pair<int, int> arr[10009];
bool check[60];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return ((a.first > b.first) || (a.first == b.first && a.second < b.second));
}
int main() {
    //freopen("bank.inp", "r", stdin);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {cin >> arr[i].first >> arr[i].second; check[i] = 0;}
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (arr[i].second < t) {
            for (int j = arr[i].second; j >= 0; j--) {
                if (!check[j]) {
                    check[j] = 1;
                    res += arr[i].first;
                    break;
                }
            }
        } else {
            for (int j = t - 1; j >= 0; j--) {
                if (!check[j]) {
                    check[j] = 1;
                    res += arr[i].second;
                    break;
                }
            }
        }

    }
    cout << res << endl;
    return 0;
}
