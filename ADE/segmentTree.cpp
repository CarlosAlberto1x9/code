#include <iostream>

using namespace std;

/*100 max elements, segment tree for partial sums*/

int arr[100+1];
int segmentTree[4*100+1];

void createSegmentTree(int indice, int l, int r) {
	if ( l == r ) {
		segmentTree[indice] = arr[l];
		return;
	} else {
		createSegmentTree(2*indice, l,(l+r)/2);
		createSegmentTree(2*indice+1, (l+r)/2 + 1,r);
		segmentTree[indice]
			= segmentTree[2*indice] + segmentTree[2*indice+1];
	}
}

void update(int indice, int l, int r, int i, int v) {
	
	if ( l == r ) {
		arr[i] = v;
		segmentTree[indice] = v;
	} else {
		if ( l <= i && i <= (l+r)/2 ) {
			update(2*indice, l, (l+r)/2, i, v);
		} else {
			update(2*indice+1, (l+r)/2+1, r, i, v);
		}
		segmentTree[indice] = segmentTree[2*indice] + segmentTree[2*indice+1];
	}
}

int query(int indice, int l, int r, int inicio, int final) {
	
	if ( final < l || r < inicio ) {
		return 0;
	}
	if ( inicio <= l && r <= final ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = query(2*indice, l, (l+r)/2, inicio, final);
	int hijoDerecho   = query(2*indice+1, (l+r)/2 + 1,r, inicio, final);
	return hijoIzquierdo + hijoDerecho;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	createSegmentTree(1,1,n);

	int a, b;
	cin >> a >> b;

	int ans = query(1, 1, n, a, b);
	cout << ans << '\n';

	update(1, 1, n, 4, 10);
	ans = query(1, 1, n, a, b);
	cout << ans << '\n';

}