#pragma warning (disable: 4996)

#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];
int d[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	d[1] = a[1];
	d[2] = max(a[2], d[1] + a[2]);

	for (int i = 3; i <= n; i++)
	{
		d[i] = max(a[i], d[i - 1] + a[i]);
	}

	long long max = -1000 * 100000;

	for (int i = 1; i <= n; i++)
	{
		if (max < d[i])
			max = d[i];
	}

	printf("%lld", max);


	return 0;
}