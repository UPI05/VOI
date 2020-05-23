#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, a[100009], b[100009], res;
deque<int> dq, pos;
int main() {
    freopen("maxdif.inp", "r", stdin);
    //freopen("maxdif.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
    dq.push_back(b[1]);
    for (int i = 2; i <= n - k - 1; i++) {
        if (dq.empty()) {
            dq.push_back(b[i]);
            pos.push_back(i);
        } else {
            if (b[i] >= dq.back()) {
                dq.push_back(b[i]);
                pos.push_back(i);
            } else {
                while (dq.size() && dq.back() > b[i]) {
                    dq.pop_back();
                    pos.pop_back();
                    dq.push_back(b[i]);
                    pos.push_back(i);
                }
            }
        }
    }
    res = dq.front();
    for (int i = n - k; i < n; i++) {
        if (dq.empty()) {
            dq.push_back(b[i]);
            pos.push_back(i);
        } else {
            if (b[i] >= dq.back()) {
                dq.push_back(b[i]);
                pos.push_back(i);
            } else {
                while (dq.size() && dq.back() > b[i]) {
                    dq.pop_back();
                    pos.pop_back();
                    dq.push_back(b[i]);
                    pos.push_back(i);
                }
            }
        }
        if (pos.front() <= (i - (n - k - 1))) {
            dq.pop_back();
            pos.pop_back();
        }
        res = min(res, dq.front());
    }
    cout << res;
    return 0;
}
