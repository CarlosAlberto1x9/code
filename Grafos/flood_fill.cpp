#include <iostream>

using namespace std;

int C, R;
char grid[9][9];

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

// trick to explore an implicit 2D grid
// S,SE,E,NE,N,NW,W,SW neighbors

int floodfill(int r, int c, char c1, char c2) {
	
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	
	if (grid[r][c] != c1) return 0;
	
	int ans = 1;
	
	grid[r][c] = c2;
	                   
	for (int d = 0; d < 8; d++)
	ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	
	return ans;
}

int main()
{
	cin >> C >> R;

	for (int i=0;i<R;++i) {
		for (int j=0;j<C;++j) {
			cin >> grid[i][j];
		}
	}

	int row, column;

	cin >> row >> column;

	// labeling 'L' to '.'
	printf("%d\n",floodfill(row,column,'L','.'));

	for (int i=0;i<R;++i) {
		for (int j=0;j<C;++j) {
			cout << grid[i][j];
		}
		cout << '\n';
	}

	return 0;
}