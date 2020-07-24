#include <bits/stdc++.h>
using namespace std;
long long ans[10000009], res[10000009];
int n, q, k, a, b;
int main() {
	freopen("arrM.inp", "r", stdin);
	freopen("arrM.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) res[i] = 0;
	while (q--) {
		cin >> a >> b >> k;
		res[a] += k;
		res[b + 1] -= k;
	}
	ans[0] = 0;
	long long tmp = 0;
	for (int i = 1; i <= n; i++) {
		ans[i] = ans[i - 1] + res[i];
		tmp = max(tmp, ans[i]);
	}
	cout << tmp;
	return 0;
}

