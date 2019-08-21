#include <cstdio>
#include <queue>

using namespace std;

int from[200001];
bool check[200001];
int dist[200001];

void printt(int start, int end)
{
	if (start != end)
	{
		printt(start, from[end]);
	}

	printf("%d ", end);
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	check[n] = true;
	dist[n] = 0;
	queue<int> x;
	x.push(n);

	while (!x.empty())
	{
		int now = x.front();
		x.pop();

		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				x.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
				from[now - 1] = now;
			}
		}
		if (now + 1 < 200001) {
			if (check[now + 1] == false) {
				x.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
				from[now + 1] = now;
			}
		}
		if (now * 2 < 200001) {
			if (check[now * 2] == false) {
				x.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
				from[now * 2] = now;
			}
		}

	}
	printf("%d\n", dist[k]);
	printt(n, k);

	return 0;
}