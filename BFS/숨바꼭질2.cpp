#include <iostream>
#include <queue>

using namespace std;

int dist[200001];
bool check[200001];
int ans[200001];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	check[n] = true;
	dist[n] = 0;
	ans[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		int temp = now + 1;
		if (temp <= 200000 && check[temp] == false)
		{
			check[temp] = true;
			dist[temp] = dist[now] + 1;
			q.push(temp);
			ans[temp] = ans[now];
		}
		else if (temp <= 200000 && check[temp] == true && dist[temp] == dist[now] + 1)
		{
			ans[temp] += ans[now];
		}

		temp = now - 1;
		if (temp >= 0 && check[temp] == false)
		{
			check[temp] = true;
			dist[temp] = dist[now] + 1;
			q.push(temp);
			ans[temp] = ans[now];
		}
		else if (temp >= 0 && check[temp] == true && dist[temp] == dist[now] + 1)
		{
			ans[temp] += ans[now];
		}

		temp = now * 2;
		if (temp <= 200000 && check[temp] == false)
		{
			check[temp] = true;
			dist[temp] = dist[now] + 1;
			q.push(temp);
			ans[temp] = ans[now];
		}
		else if (temp <= 200000 && check[temp] == true && dist[temp] == dist[now] + 1)
		{
			ans[temp] += ans[now];
		}
	}

	printf("%d\n%d", dist[m], ans[m]);

	return 0;
}