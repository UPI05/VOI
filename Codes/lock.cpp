#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
long long n, k, s, arr[100009], res = 0;
bool check[100009];
vector<long long> val;
int main() {
    freopen("lock.inp", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        check[i] = 0;
    }
    for (int i = 1; i <= s; i++) {
        if (check[i]) continue;
        val.clear();
        int x = i;
        check[i] = 1;
        val.push_back(arr[i]);
        x = (x + s) % n;
        if (x == 0) x = n;
        while (x != i) {
            val.push_back(arr[x]);
            check[x] = 1;
            x = (x + s) % n;
            if (x == 0) x = n;
        }
        sort(val.begin(), val.end());
        long long ans = val[(int) val.size() / 2];
        for (int j = 0; j < val.size(); j++) res += abs(val[j] - ans);
    }
    cout << res;
    return 0;
}
