#include <iostream>
#include <fstream>
#include <cmath>
#include <unordered_map>
using namespace std;
int n, res = 0;
struct dt{
    double a, b, c;
} arr[1009];
unordered_map<double, bool> umap;
int main() {
    freopen("equa.inp", "r", stdin);
    freopen("equa.out", "w", stdout);
    umap.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        if (arr[i].a == 0 && arr[i].b == 0 && arr[i].c == 0) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i].a == 0) {
            if (arr[i].b == 0) continue;
            umap[(- arr[i].c / arr[i].b)] = 1;
            continue;
        }
        double delta = arr[i].b * arr[i].b - 4 * arr[i].a * arr[i].c;
        if (delta == 0) {
            umap[((- arr[i].b) / (2 * arr[i].a))] = 1;
        }
        if (delta > 0) {
            umap[(- arr[i].b + sqrt(delta)) / (2 * arr[i].a)] = 1;
            umap[(- arr[i].b - sqrt(delta)) / (2 * arr[i].a)] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i].a == 0) {
            if (arr[i].b == 0) continue;
            if (umap[(- arr[i].c / arr[i]. b)] == 1) {
                res++;
                umap[(- arr[i].c / arr[i]. b)] = 0;
            }
            continue;
        }
        double delta = arr[i].b * arr[i].b - 4 * arr[i].a * arr[i].c;
        if (delta == 0) {
            if (umap[((- arr[i].b) / (2 * arr[i].a))] == 1) {
                res++;
                umap[((- arr[i].b) / (2 * arr[i].a))] = 0;
            }

        }
        if (delta > 0) {
            if (umap[(- arr[i].b + sqrt(delta)) / (2 * arr[i].a)] == 1) {
                res++;
                umap[(- arr[i].b + sqrt(delta)) / (2 * arr[i].a)] = 0;
            }
            if (umap[(- arr[i].b - sqrt(delta)) / (2 * arr[i].a)] == 1) {
                res++;
                umap[(- arr[i].b - sqrt(delta)) / (2 * arr[i].a)] = 0;
            }
        }
    }
    cout << res;
    return 0;
}
