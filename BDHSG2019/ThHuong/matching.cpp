/*
Bài này quy về đồ thị có 4 đỉnh, sẽ có tối đa 4 thành phần liên thông. Với mỗi thành phần liên thông, ta xem như một đồ thị mới.
Ta cần xóa 1 số cạnh để đưa đồ thị đó về đồ thị nửa euler (là đồ thị có tất cả các đỉnh đều bậc chẵn hoặc có duy nhất 2 đỉnh bậc lẻ) 
có trọng số lớn nhất.
Kết quả chính là trọng số lớn nhất của các đồ thị nửa euler tìm được.
Nhận xét:
- Với thành phần liên thông có 1, 2 hoặc 3 đỉnh thì tổng trọng số các cạnh chính là trọng số của đồ thị nửa euler cần tìm.
- Với thành phần liên thông có 4 đỉnh:
  + Nếu 4 đỉnh đó đều có bậc lẻ thì ta cần xóa 1 cạnh bất kỳ (khác khuyên) trong thành phần liên thông đó sao cho tổng trọng số của
  đồ thị nửa euler tìm được là lớn nhất.
  + Ngược lại thì tổng trọng số các cạnh chính là trọng số của đồ thị nửa euler cần tìm.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int n, deg[5] = {0, 0, 0, 0, 0}, pos = 0, sum = 0, matrix[5][5];
pair<int, pair<int, int> > arr[109];
bool check[5] = {0, 0, 0, 0, 0};
vector<int> compoList[5];
void getCompo(int k) {
    check[k] = 1;
    compoList[pos].push_back(k);
    for (int i = 1; i <= 4; i++) if (!check[i] && matrix[k][i] > 0) getCompo(i);
}
int main() {
    freopen("matching.inp", "r", stdin);
    freopen("matching.out", "w", stdout);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) matrix[i][j] = 0;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].second.first >> arr[i].first >> arr[i].second.second;
        deg[arr[i].second.first]++;
        deg[arr[i].second.second]++;
        sum += arr[i].first;
        matrix[arr[i].second.first][arr[i].second.second]++;
        matrix[arr[i].second.second][arr[i].second.first]++;
    }
    for (int i = 1; i <= 4; i++) {
        if (!check[i]) {
            pos++;
            getCompo(i);
        }
    }
    if (compoList[1].size() == 4) {
        if ((deg[1] % 2) && (deg[2] % 2) && (deg[3] % 2) && (deg[4] % 2)) {
            /*
            // Đoạn code này sai trong trường hợp cạnh Min là cầu.
            int Min = 1000000009;
            for (int i = 1; i <= n; i++) {
                if (arr[i].second.first != arr[i].second.second) {
                    Min = min(Min, arr[i].first);
                }
            }
            cout << sum - Min << endl;
            */
            sum = 0;
            for (int i = 1; i <= n; i++) {
                if (arr[i].second.first != arr[i].second.second) {
                    matrix[arr[i].second.first][arr[i].second.second]--;
                    matrix[arr[i].second.second][arr[i].second.first]--;
                    int k = arr[i].first;
                    arr[i].first = 0;
                    check[1] = check[2] = check[3] = check[4] = 0;
                    compoList[1].clear(); compoList[2].clear(); compoList[3].clear(); compoList[4].clear();
                    pos = 0;
                    for (int j = 1; j <= 4; j++) if (!check[j]) {
                        pos++;
                        getCompo(j);
                    }
                    for (int j = 1; j <= 4; j++) {
                        if (!compoList[j].size()) continue;
                        int sum1 = 0;
                        for (int x = 1; x <= n; x++) {
                            for (int z = 0; z < compoList[j].size(); z++) {
                                if (arr[x].second.first == compoList[j][z] || arr[x].second.second == compoList[j][z]) {
                                    sum1 += arr[x].first;
                                    break;
                                }
                            }
                        }
                        sum = max(sum1, sum);
                    }
                    arr[i].first = k;
                    matrix[arr[i].second.first][arr[i].second.second]++;
                    matrix[arr[i].second.second][arr[i].second.first]++;
                }
            }
            cout << sum << endl;
        } else {
            cout << sum << endl;
        }
    } else {
        sum = 0;
        for (int i = 1; i <= 4; i++) {
            int sum1 = 0;
            if (!compoList[i].size()) continue;
            for (int j = 1; j <= n; j++) {
                for (int z = 0; z < compoList[i].size(); z++) {
                    if (arr[j].second.first == compoList[i][z] || arr[j].second.second == compoList[i][z]) {
                        sum1 += arr[j].first;
                        break;
                    }
                }
            }
            sum = max(sum, sum1);
        }
        cout << sum << endl;
    }
    return 0;
}
