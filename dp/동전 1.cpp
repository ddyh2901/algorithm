#include <iostream>

using namespace std;

long long a[101];
long long d[10001];

int main(void)
{
	int n, sum;
	scanf("%ld %ld", &n, &sum);

	for (int i = 0; i < n; i++)
		scanf("%ld", &a[i]);

	d[0] = 1;

	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= sum; i++)
		{
			if (i - a[j] >= 0)
			{
				d[i] += d[i - a[j]];
			}
		}
	}

	printf("%lld", d[sum]);
	return 0;
}