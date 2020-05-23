#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
int n, k, sta, s;
bool check[10009];
int leftArr[10009], rightArr[10009];
int main() {
    freopen("fcoin.inp", "r", stdin);
    freopen("fcoin.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) check[i] = 1;
    for (int i = 1; i <= k; i++) {
        cin >> s;
        for (int j = 1; j <= s; j++) cin >> leftArr[j];
        for (int j = 1; j <= s; j++) cin >> rightArr[j];
        cin >> sta;
        unordered_map<int, bool> umap;
        if (sta == 1) {
            for (int j = 1; j <= s; j++) check[leftArr[j]] = 0;
            for (int j = 1; j <= s; j++) umap[rightArr[j]] = 1;
            for (int j = 1; j <= n; j++) {
                if (check[j]) {
                    if (!umap[j]) {
                        check[j] = 0;
                    }
                }
            }
        } else if (sta == 2) {
            for (int j = 1; j <= s; j++) check[rightArr[j]] = 0;
            for (int j = 1; j <= s; j++) umap[leftArr[j]] = 1;
            for (int j = 1; j <= n; j++) {
                if (check[j]) {
                    if (!umap[j]) {
                        check[j] = 0;
                    }
                }
            }
        } else {
            for (int j = 1; j <= s; j++) {
                check[leftArr[j]] = 0;
                check[rightArr[j]] = 0;
            }
        }
    }
    int pos, Count = 0;
    for (int i = 1; i <= n; i++) if (check[i]) {
        pos = i;
        Count++;
    }
    if (Count > 1) cout << 0;
    else cout << pos;
    return 0;
}
