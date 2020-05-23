// This solution is used to solve "Lakes in Berland" problem.
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int n, m, k;
char arr[59][59], arr2[59][59];
bool check[59][59];
struct data {
	int value;
	int posx, posy;
};
vector <data> res;
bool cmp(data a, data b) {
	return a.value < b.value;
}
void Replace(int x, int y, int k) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	if (k == 1) {
		arr[x][y] = '*';
		if (arr[x + 1][y] == '.') Replace(x + 1, y, 1);
		if (arr[x - 1][y] == '.') Replace(x - 1, y, 1);
		if (arr[x][y + 1] == '.') Replace(x, y + 1, 1);
		if (arr[x][y - 1] == '.') Replace(x, y - 1, 1);
	} else {
		arr2[x][y] = '*';
		if (arr2[x + 1][y] == '.') Replace(x + 1, y, 2);
		if (arr2[x - 1][y] == '.') Replace(x - 1, y, 2);
		if (arr2[x][y + 1] == '.') Replace(x, y + 1, 2);
		if (arr2[x][y - 1] == '.') Replace(x, y - 1, 2);
	}
}
void Count(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	res[res.size() - 1].value++;
	check[x][y] = true;
	if (arr[x + 1][y] == '.' && !check[x + 1][y]) Count(x + 1, y);
	if (arr[x - 1][y] == '.' && !check[x - 1][y]) Count(x - 1, y);
	if (arr[x][y + 1] == '.' && !check[x][y + 1]) Count(x, y + 1);
	if (arr[x][y - 1] == '.' && !check[x][y - 1]) Count(x, y - 1);
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {cin >> arr[i][j]; arr2[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i][1] == '.') Replace(i, 1, 1);
		if (arr[i][m] == '.') Replace(i, m, 1);
	}
	for (int i = 1; i <= m; i++) {
		if (arr[1][i] == '.') Replace(1, i, 1);
		if (arr[n][i] == '.') Replace(n, i, 1);
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) check[i][j] = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (arr[i][j] == '.' && !check[i][j]) {
				data a; a.value = 0, a.posx = i, a.posy = j; res.push_back(a);		
				Count(i, j);
			}
		}
	}
	sort(res.begin(), res.end(), cmp);
	int ans = 0;
	for (int i = 0; i < res.size() - k; i++) {ans += res[i].value; Replace(res[i].posx, res[i].posy, 2);} 
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << arr2[i][j]; cout << endl;
	}
	return 0;
}
