#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001];
int d[1001][1001];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max(d[i - 1][j], max(d[i][j - 1], d[i - 1][j - 1])) + a[i][j];
		}
	}

	printf("%d", d[n][m]);


	return 0;
}