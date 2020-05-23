#include <bits/stdc++.h>
using namespace std;
int n, a[200009];
bool checkIn[200009], checkOut[200009];
int main() {
    freopen("a.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) checkIn[i] = checkOut[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        checkIn[a[i]] = 1;
        if (a[i]) checkOut[i] = 1;
    }
    vector<int> In, Out, None;
    for (int i = 1; i <= n; i++) {
        if (checkIn[i] && !checkOut[i]) {
            In.push_back(i);
        } else if (checkOut[i] && !checkIn[i]) {
            Out.push_back(i);
        } else if (!checkIn[i] && !checkOut[i]) {
            None.push_back(i);
        }
    }
    if (None.size()) {
        if (In.size()) {
            a[In[0]] = None[0];
            for (int i = 0; i < (int) None.size() - 1; i++) {
                a[None[i]] = None[i + 1];
            }
            a[None[(int) None.size() - 1]] = Out[0];
            for (int i = 1; i < In.size(); i++) {
                a[In[i]] = Out[i];
            }
        } else {
            for (int i = 0; i < (int) None.size() - 1; i++) {
                a[None[i]] = None[i + 1];
            }
            a[None[(int) None.size() - 1]] = None[0];
        }
    } else {
        for (int i = 0; i < In.size(); i++) {
            a[In[i]] = Out[i];
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
