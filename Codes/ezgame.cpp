#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> ans;
int main() {
    getline(cin, s);
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (t != "") {
                ans.push_back(t);
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if (t != "") ans.push_back(t);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
