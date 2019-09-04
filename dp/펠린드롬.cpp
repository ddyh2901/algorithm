#include <iostream>
#include <cstring>

using namespace std;

int a[2001];
int d[2001][2001];

int go(int x, int y)
{
	if (x == y)
		return 1;
	if (x + 1 == y)
	{
		if (a[x] == a[y])
			return 1;
		else
			return 0;
	}
	if (d[x][y] >= 0)
		return d[x][y];
	if (a[x] != a[y])
		return 0;
	return go(x + 1, y - 1);
}

int main(void)
{
	memset(d, -1, sizeof(d));
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int num;
	scanf("%d", &num);

	int x, y;

	for (int i = 1; i <= num; i++)
	{
		scanf("%d %d", &x, &y);

		d[x][y] = go(x, y);
		printf("%d\n", d[x][y]);
	}
	return 0;
}