#pragma warning (disable: 4996)

#include <cstdio>

using namespace std;

int a[1001];
int d[1001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	int max = -1;
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i];
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i] && d[i] < d[j] + a[i])
			{
				d[i] = d[j] + a[i];
			}
		}
		if (max < d[i])
			max = d[i];
	}

	printf("%d", max);

	return 0;
}