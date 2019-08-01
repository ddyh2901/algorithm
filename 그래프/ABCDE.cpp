#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

int main() {
	
	int n, m;
	scanf("%d %d", &n, &m);

	int from, to;
	for (int i = 0; i < m; i++){
		scanf("%d %d", &from, &to);
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		a[from][to] = true;
		a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	
	for (int i = 0; i < m * 2; i++) {
		for (int j = 0; j < m * 2; j++) {
			int A = edges[i].first;
			int B = edges[i].second;
			int C = edges[j].first;
			int D = edges[j].second;
			int E;

			if (!a[B][C]) {
				continue;
			}

			if (A == B || A == C || A == D || B == C || B == D || C == D) {
				continue;
			}

			for (int i = 0; i < g[D].size(); i++) {
				E = g[D][i];
				if (A == E || B == E || C == E || D == E)
					continue;
				printf("1");
				return 0;
			}
		}
	}
	printf("0");
	return 0;
}