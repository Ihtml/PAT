#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 求起点到终点的最短距离和花费，路径最短优先，距离一样时花费最少优先，输出完整路径
const int N = 502, inf = INT_MAX;
int n, m, s, d, mincost = inf;
int e[N][N], dis[N], cost[N][N];
vector<int> pre[N];
bool visit[N];
vector<int> path, temppath;
// DFS求最短的mincost和路径path
void dfs(int v) {
    temppath.push_back(v);
    if (v == s) {
        int tempcost = 0;
        for (int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i - 1];
            tempcost += cost[id][nextid];
        }
        if (tempcost < mincost) {
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
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
    // Dijkstra求最短路径，记录在pre数组
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);  // 从终点往起点DFS
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[d], mincost);
    return 0;
}