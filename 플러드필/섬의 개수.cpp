#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int land[100][100];
bool check[100][100];
int dx[] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int row, column;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (0 <= next_x && next_x < row && 0 <= next_y && next_y < column) {
				if (land[next_x][next_y] == 1 && check[next_x][next_y] == false) {
					q.push(make_pair(next_x, next_y));
					check[next_x][next_y] = true;
				}
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		scanf("%d %d", &column, &row);

		if (row == 0 && column == 0)
			break;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				scanf("%1d", &land[row][column]);
				check[row][column] = false;
			}
		}


		int cnt = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (land[row][column] == 1 && check[row][column] == false)
				{
					bfs(row, column);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		memset(check, false, sizeof(check));
		memset(land, 0, sizeof(land));
	}

	return 0;
}