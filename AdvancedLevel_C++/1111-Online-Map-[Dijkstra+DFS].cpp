/*
Q:给一张地图，两个结点中既有距离也有时间，有的单行有的双向，要求根据地图推荐两条路线：一条是最快到达路线，一条是最短距离的路线。
A:用两个Dijkstra。一个求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）
求最快路径时候要多维护一个NodeNum数组，记录在时间最短的情况下，到达此节点所需的节点数量;
Time数组更新的条件是，时间更短，时间相同的时候，如果此节点能让到达次节点是数目也变小，则更新Timepre，和NodeNum数组
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
    int a, b, flag , len, t;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if (flag != 1) {  // 双向边
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for (int i = 0; i < n; i++) {
        dispre[i] = i;  // 初始化距离前驱数组
    }
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];  // 更新最小距离和节点
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
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
                           Time[v] && NodeNum[u] + 1 < NodeNum[v]) {
                    Timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if (dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for (int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if (i != 0)
                printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for (int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if (i != 0)
            printf(" -> ");
    }
    return 0;
}
