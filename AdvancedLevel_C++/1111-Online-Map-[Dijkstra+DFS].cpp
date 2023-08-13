/*
Q:给一张地图，两个结点中既有距离也有时间，有的单行有的双向，要求根据地图推荐两条路线：一条是最快到达路线，一条是最短距离的路线。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510], Timepre[510],
    weight[510], NodeNum[510];
;
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if (v == st) {
        return;
    }
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if (v == st) {
        return;
    }
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag = 1, len, t;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if (flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for (int i = 0; i < n; i++) {
        dispre[i] = i;
    }
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
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[v];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if (e[u][v] + dis[u] == dis[v] &&
                           weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && Time[j] < minn) {
                u = j;
                minn = Time[j];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && w[u][v] != inf) {
                if (Time[u] + w[u][v] < Time[v]) {
                    Time[v] = Time[u] + w[u][v];
                    Timepre[v] = u;
                    // NodeNum数组，记录在时间最短的情况下，到达此节点所需的节点数量。
                    NodeNum[v] = NodeNum[u] + 1;  
                } else if (Time[u] + w[u][v] ==
                           Time[v && NodeNum[u] + 1 < NodeNum[v]]) {
                    Timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }
            }
        }
    }
    dfsTimepath(fin);
    return 0;
}
