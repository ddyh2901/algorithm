#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

char a[51][51];
int water[51][51];
int d[51][51];
int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(water, -1, sizeof(water));
	queue<pair<int, int>> q;
	int sx, sy, ex, ey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 'X' && a[nx][ny] != 'D' && a[nx][ny] != 'S' && water[nx][ny] == -1)
			{
				q.push(make_pair(nx, ny));
				water[nx][ny] = water[x][y] + 1;
			}
		}
	}

	memset(d, -1, sizeof(d));
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (d[nx][ny] != -1) continue;
			if (a[nx][ny] == 'X') continue;
			if (water[nx][ny] != -1 && d[x][y] + 1 >= water[nx][ny]) continue;
			d[nx][ny] = d[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	if (d[ex][ey] == -1) {
		printf("KAKTUS");
	}
	else {
		printf("%d",d[ex][ey]);
	}

	return 0;
}
