#include <iostream>
#include <algorithm>

using namespace std;

long long d[101];

int main(void)
{
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;

	int n;
	scanf("%d", &n);

	for (int i = 4; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++)
		{
			d[i] = max(d[i], d[i - j - 2] * (j + 1));
		}
	}

	printf("%lld", d[n]);

	return 0;
}