#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
set<int> s;
unordered_set<int> uset;
int main() {
    // set
    // Search, Insert, Delete: O(log(n))
    s.insert(3);
    s.insert(40);
    s.insert(6);
    s.insert(10);
    if (s.find(40) == s.end()) {
        cout << "Not found!" << endl;
    } else {
        cout << "Found!" << endl;
    }
    set<int>:: iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;
    it = s.lower_bound(7);
    cout << *it << endl;
    s.erase(40);
    auto it2 = s.upper_bound(10);
    cout << *s.end() << endl;
    cout << *it2 << endl;
    // unordered_set
    // Search, Insert, Delete: O(1) in average, O(n) in worst case
    uset.insert(3);
    uset.insert(7);
    uset.insert(4);
    uset.insert(8);
    for (auto x: uset) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
