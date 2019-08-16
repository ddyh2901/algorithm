#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	int n;
	int a, b, c, d;


	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int count = -1;

		scanf("%d %d %d %d", &a, &b, &c, &d);

		int temp = lcm(a, b);

		for (int j = c; j <= temp; j = j + a)
		{

			if ((j % b) == d || (j % b) == 0 && b == d)
			{
				count = j;
				break;
			}
		}
		printf("%d", count);
		if (i != n - 1)
			printf("\n");
	}

	return 0;
}