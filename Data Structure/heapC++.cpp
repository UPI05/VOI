#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int q, k;
struct dt {
    int u, v, w;
} x;
struct cmp {
    bool operator() (dt a, dt b) {
        return a.w < b.w;
    }
};
priority_queue<dt, vector<dt>, cmp> pq;
int main() {
    cin >> q;
    while (q--) {
        cin >> k;
        if (k == 0) {
            cin >> x.u >> x.v >> x.w;
            pq.push(x);
        } else if (k == 1) {
            if (pq.size()) pq.pop();
        } else {
            if (pq.size()) cout << pq.top().u << " " << pq.top().v << " " << pq.top().w << endl;
        }
    }
    return 0;
}
