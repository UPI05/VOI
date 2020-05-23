#include <bits/stdc++.h>
using namespace std;
int n;
struct dt {
    int a, b, c;
} arr[300009];
unordered_map<long long, int> umap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].c = __gcd(arr[i].a, arr[i].b);
        long long x = arr[i].a / arr[i].c;
        x *= 1e8;
        x += (arr[i].b / arr[i].c);
        umap[x]++;
    }

    for (int i = 1; i <= n; i++) {
        long long x = arr[i].a / arr[i].c;
        x *= 1e8;
        x += (arr[i].b / arr[i].c);

    }

    return 0;
}
