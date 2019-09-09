#include <iostream>
#include <cstring>

using namespace std;

int a[101];
int d[10001];

int main() {
	int n, sum;
	scanf("%d %d", &n, &sum);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	memset(d, -1, sizeof(d));

	d[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - a[i] >= 0 && d[j - a[i]] != -1) {
				if (d[j] == -1 || d[j] > d[j - a[i]] + 1) {
					d[j] = d[j - a[i]] + 1;
				}
			}
		}
	}

	printf("%d", d[sum]);

	return 0;
}