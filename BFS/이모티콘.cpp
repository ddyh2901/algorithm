#include <cstdio>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int d[1001][1001];

int main() {
    
    int n;
    scanf("%d", &n);
    
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));    
    d[1][0] = 0;
    
    while (!q.empty()) {
        int s = q.front().first;
        int c = q.front().second;
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s,s));
        }
        if (s+c <= n && d[s+c][c] == -1) {
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c, c));
        }
        if (s-1 >= 0 && d[s-1][c] == -1) {
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
    int ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
