#pragma warning (disable: 4996)

#include <cstdio>

using namespace std;

long long d[201][201];

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);


	d[0][0] = 1LL;
	for (int k = 1; k <= b; k++)
	{
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				d[k][i] += d[k - 1][i - j];
				d[k][i] %= 1000000000;
			}
		}
	}

	printf("%lld", d[b][a]);

	return 0;
}