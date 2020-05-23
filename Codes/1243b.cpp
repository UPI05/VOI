#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int k, n;
string s, t;
int main() {
    //freopen("a.inp", "r", stdin);
    cin >> k;
    while (k--) {
        vector<pair<int, int> > res;
        cin >> n;
        cin >> s >> t;
        s = " " + s; t = " " + t;
        bool check = true;
        for (int i = 1; i < t.length(); i++) {
            if (s[i] == t[i]) continue;
            bool ok = false; int pos;
            for (int j = i + 1; j < t.length(); j++) {
                if (t[j] == t[i]) {
                    ok = true;
                    pos = j;
                    break;
                }
            }
            if (ok) {
                res.push_back(make_pair(i, pos));
                swap(s[i], t[pos]);
            } else {
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[j] == t[i]) {
                        ok = true;
                        pos = j;
                        break;
                    }
                }
                if (ok) {
                    res.push_back(make_pair(pos, i + 1));
                    swap(s[pos], t[i + 1]);
                    res.push_back(make_pair(i, i + 1));
                    swap(s[i], t[i + 1]);
                } else {
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            cout << "Yes" << endl;
            cout << res.size() << endl;
            for (int i = 0; i < res.size(); i++) {
                cout << res[i].first << " " << res[i].second << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
