#include <bits/stdc++.h>
using namespace std;
int n, q, a[40009], cnt = 0, tmp, pos;
void upheap(int u) {
	if (u <= 1) return;
	int x = u / 2;
	if (a[x] <= a[u]) return;
	swap(a[x], a[u]);
	upheap(x);
}
void downheap(int u) {
	if (u > cnt / 2) return;
	int x = u * 2;
	if (a[x] > a[x + 1] && x + 1 <= cnt) x++;
	if (a[u] <= a[x]) return;
	swap(a[u], a[x]);
	downheap(x);	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// Insert n element(s) to heap
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		cnt++;
		a[cnt] = tmp;
		upheap(cnt);
	}
	// Update element at position pos with value tmp
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> pos >> tmp;
		if (tmp > a[pos]) {
			a[pos] = tmp;
			downheap(pos);
		} else {
			a[pos] = tmp;
			upheap(pos);
		}
	}	
	// Remove element at position pos
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> pos;
		swap(a[pos], a[cnt]);
		cnt--;	
		downheap(pos);
	}
	

}
