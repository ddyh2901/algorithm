#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());

	memset(check, false, sizeof(check));
	dfs(start);
	puts("");

	memset(check, false, sizeof(check));
	bfs(start);
	puts("");

	return 0;
}