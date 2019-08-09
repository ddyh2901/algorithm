#pragma warning (disable: 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int price[1001];
int d[1001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &price[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = 10001;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = min(d[i], d[i - j] + price[j]);
		}
	}

	printf("%d", d[n]);

	return 0;
}