#include <bits/stdc++.h>
using namespace std;
int n, x;
struct Node {
	int v;
	Node *l, *r;
};
Node *createNode(int x) {
	Node *tmp = new Node;
	tmp->v = x;
	tmp->l = tmp->r = NULL;
	return tmp;
}
Node *insertNode(Node *T, int x) {
	if (T == NULL) T = createNode(x);
	else if (T->v > x) T->l = insertNode(T->l, x);
	else T->r = insertNode(T->r, x);
	return T;
}
void duyetGiua(Node *T) {
	if (T == NULL) return;
	duyetGiua(T->l);
	cout << T->v << endl;
	duyetGiua(T->r);
}
bool Search(Node *T, int x) {
	if (T == NULL) return 0;
	if (x == T->v) return 1;
	if (x > T->v) return Search(T->r, x);
	else return Search(T->l, x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node *T = new Node;
	T = NULL;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		T = insertNode(T, x);
	}	
	duyetGiua(T);	
	cin >> x;
	cout << Search(T, x);
	return 0;
}
