//Ta có thể vạch được 1 chu trình Euler trong đồ thị liên thông (G) có bậc của mọi đỉnh là chẵn theo thuật toán Fleury sau:
//Xuất phát từ 1 đỉnh bất kỳ của đồ thị (G) và tuân theo 2 quy tắc sau:
//1.Mỗi khi đi qua một cạnh nào đó thì xóa nó đi, sau đó xóa đỉnh cô lập (nếu có).
//2.Không bao giờ đi qua cầu trừ khi không còn cách đi nào khác.
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;
int n, m, arr[300][300], a, b;
vector<int> res;
stack<int> st;
int main() {
    freopen("euler.inp", "r", stdin);
    //freopen("euler.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) arr[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        arr[a][b] ++;
        arr[b][a] ++;
    }
    st.push(1);
    while (st.size()) {
        int u = st.top();
        bool ok = true;
        for (int i = 1; i <= n; i++) if (arr[u][i]) {
            arr[u][i] --;
            arr[i][u] --;
            st.push(i);
            ok = false;
            break;
        }
        if (ok) {res.push_back(u); st.pop();}
    }
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}
