#include <bits/stdc++.h>
using namespace std;
int n, x;
long long white = 0, black = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i % 2) {
            white += x / 2;
            black += x / 2;
            if (x % 2) {
                black++;
            }
        } else {
            white += x / 2;
            black += x / 2;
            if (x % 2) {
                white++;
            }
        }
    }
    cout << min(white, black);
    return 0;
}
