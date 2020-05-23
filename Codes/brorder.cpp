#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
int t, pos;
string s;
string st;
bool isOK(string s) {
    stack<bool> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(1);
        else {
            if (!st.size()) return 0;
            else st.pop();
        }
    }
    if (st.size()) return 0;
    return 1;
}
void backTrack(int k) {
    for (char c = '('; c <= ')'; c++) {
        st += c;
        if (k == (s.length())) {
            if (isOK(st)) {
                if (st == s) {
                    cout << pos << endl;
                    return;
                } else pos++;
            }
        } else {
            backTrack(k + 1);
        }
        st.erase(st.end() - 1, st.end());
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        st.clear();
        pos = 1;
        backTrack(1);
    }
    return 0;
}
