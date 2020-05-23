#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <utility>
using namespace std;
unordered_map<string, int> umap;
map<string, int> mp;
int main() {
    // unordered_map
    // Search, Insert, Delete: O(1) in average, O(n) in worst case
    umap["Kasper01"] = 10;
    umap["Kasper02"] = 15;
    umap["Kasper03"] = 20;
    cout << umap["Kasper01"] << endl;
    umap["Kasper01"] = 0;
    cout << umap["Kasper01"] << endl;
    umap.erase("Kasper02");
    if (umap.find("Kasper01") == umap.end()) {
        cout << "Key not found!" << endl;
    } else {
        cout << "Map value: " << umap.find("Kasper01")->second << endl;
    }
    for (auto x: umap) {
        cout << x.first << " " << x.second << endl;
    }
    unordered_map<string, int>:: iterator it;
    for (it = umap.begin(); it != umap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
    // map
    // Search, Insert, Delete: O(log(n))
    mp["Kasper04"] = 25;
    mp["Kasper05"] = 30;
    mp["Kasper06"] = 35;
    cout << mp["Kasper04"] << endl;
    mp["Kasper04"] = 40;
    for (auto x: mp) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
