#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;  // 每个点最大容量cmax  点的数量n 问题点sp  边数m
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510];
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[a][b] = e[a][b];
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v <= n; v++) {
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
    
    return 0;
}