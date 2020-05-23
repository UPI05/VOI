#include <iostream>
#include <fstream>
using namespace std;
int n, time1[100009], time2[100009, res = 1e9;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> time1[i];
        time2[i] = time1[i];
    }

    return 0;
}
/*
    Gọi f[i][j] là số bước Min để với mọi dồng hồ trước i về 12h với đồng hồ thứ i ở vị trí j h, k* là số bước chuyển từ a[i] về j -> k = 12 -k*;

    f[i][j] = f[i - 1][k] + k*
    res = Min(f[n, j] + 12 -j)
*/
