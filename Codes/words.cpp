#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int n, k, res = 0;
char c[109][109];
map<string, bool> umap;
string s;
int main() {
    //freopen("words.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s; s = '1' + s;
        umap[s] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s = "1";
            for (int z = j; z <= n; z++) {
                s += c[i][z];
                if (umap[s]) res++;
            }
        }
    }
    cout << res;
    return 0;
}
