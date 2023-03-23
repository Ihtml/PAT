#include <iostream>
#include <limits>
#include <vector>
using namespace std;
const int N = 502, inf = INT_MAX;
int n, m, s, d, mincost = inf;
int e[N][N], dis[N], cost[N][N];
vector<int> pre[N];
bool visit[N];
vector<int> path, temppath;

int main() {
    fill(e[0], e[0] + N * N, inf);
    fill(dis, dis + N, inf);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[b][a]);
        e[a][b] = e[b][a];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    pre[s].push_back(s);  // s是起点
    dis[s] = 0;

    return 0;
}