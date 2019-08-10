#pragma warning (disable: 4996)

#include <cstdio>

using namespace std;

long long d[101][10];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1)
				d[i][j] = 1;
			else
			{
				if (j - 1 >= 0 && j + 1 < 10)
					d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
				else if (j == 0)
					d[i][j] = d[i - 1][j + 1];
				else if (j == 9)
					d[i][j] = d[i - 1][j - 1];

				d[i][j] %= 1000000000;
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum += d[n][i];
		sum %= 1000000000;
	}

	printf("%lld", sum);

	return 0;
}