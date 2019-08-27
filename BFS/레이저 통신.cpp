#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<string> a(m);

	int sx, sy, ex, ey;
	sx = -1;
	sy = -1;
	ex = -1;
	ey = -1;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'C') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	
	vector<vector<int>> d(m, vector<int>(n, -1));
	d[sx][sy] = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			while (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (a[nx][ny] == '*') break;
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}

	printf("%d", d[ex][ey] -1); 
	return 0;
}