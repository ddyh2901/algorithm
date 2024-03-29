﻿#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

bool check[10001];
int dist[10001];
int from[10001];
char how[10001];

void print(int n, int m) {
	if (n == m) return;
	print(n, from[m]);
	printf("%c", how[m]);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));

		check[a] = true;
		dist[a] = 0;
		from[a] = -1;

		queue<int> q;
		q.push(a);

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			int next = (now * 2) % 10000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'D';
			}
			next = now - 1;
			if (next == -1) next = 9999;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'S';
			}
			next = (now % 1000) * 10 + now / 1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'L';
			}
			next = (now / 10) + (now % 10) * 1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'R';
			}
		}
		print(a, b);
		printf("\n");
	}

	return 0;
}