#include <bits/stdc++.h>
using namespace std;
int n, a, cnt = 0, sum = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
        if (a == 200) cnt++;
    }
    if (sum % 200) {
        cout << "NO";
        return 0;
    }
    if (cnt == n) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
