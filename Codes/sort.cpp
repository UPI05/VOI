#include <iostream>
#include <fstream>
using namespace std;
int n, res = 0;
int arr[200009], Max[200009];
int main() {
    freopen("sort.inp", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    Max[0] = -1000000009;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        Max[i] = max(Max[i - 1], arr[i]);
    }
    int Min = 1000000009;
    for (int i = n; i > 0; i--) {
        Min = min(Min, arr[i]);
        if (Max[i - 1] <= Min) {
            Min = 1000000009;
            res++;
        }
    }
    cout << res;
    return 0;
}
