#include <bits/stdc++.h>
using namespace std;
int n, a[3], b[10], res = 0;
map<int, bool> Map;
void backTrack(int k) {
	for (int i = 0; i <= 2; i++) {
		b[k] = a[i];
		if (k == 9) {
			long long ans = 0;
			bool check0 = 0, check1 = 0, check2 = 0;
			for (int j = 1; j <= 9; j++) {
				if (b[j] == a[0]) check0 = 1;
				if (b[j] == a[1]) check1 = 1;
				if (b[j] == a[2]) check2 = 1; 
				ans *= 10;
				ans += b[j];
			}
			long long x = ans;
			bool f = 0;
			while (x) {
				int u = x % 10;
				if (u == 0) f = 1;	
				x /= 10;
			}
			if (a[1] != 0 && a[0] != 0 && f) continue;
			if (ans > 0 && ans <= n && !Map[ans]) {
				res++;
				Map[ans] = 1;
			}
							
		} else {
			backTrack(k + 1);
		}
	}
}
int main() {
	freopen("ulnumber.inp", "r", stdin);
	freopen("ulnumber.out", "w", stdout);
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			a[0] = i; a[1] = j;
			a[2] = 0;
			backTrack(1);
		}
	}
	if (n == 1000000000) cout << res + 1;
	else cout << res;
	return 0;
}
