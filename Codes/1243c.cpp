#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
long long n;
int main() {
    cin >> n;
    long long ans = n;
    for (long long i = 2; i <= (long long) sqrt(n); i++) {
        if (n % i == 0) {
            if (i != 1) ans = min(ans, i);
        }
        if (n % (n / i) == 0) {
            if ((n / i) != 1) ans = min(ans, n / i);
        }
    }
    cout << ans;
    return 0;
}
