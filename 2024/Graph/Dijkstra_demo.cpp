/*
Q:有N个城市(编号为0~N-1)、M条道路(无向边)，开给出M条道路的距离属性与化费属性。现在给定起点S与终点D,求从起点到终点的最短路径、最短距离及花费。注意:
如果有多条最短路径，则选择花费最小的那条。
A:
对只使用Djkstra算法的写法，令cost[MAXV][MAXV]表示顶点间的花费(
也即边权)，c[MAXV]存放从起点s到达每个结点u的在最短路径下的最小花费,其中c[s]在初始化时为0。
而针对最短路径，可以用int型pre数组存放每个结点的前驱，接下来就是按前面讲解的过程在最短距离的更新过程中同时更新数组c和数组pre,
代码如下:
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXV = 510;       // 最大顶点数
const int INF = 100000000;  // 无穷大

// n为顶点数，m为边数，st和ed分别为起点和终点
// G为距离矩阵， cost为花费矩阵
// d[]记录最短距离，c[]记录最小花费
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV], pre[MAXV];
bool vis[MAXV] = {false};  // vis[i]==true表示顶点i已访问，初值均为false

void Dijkstra(int s) {  // s为起点
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    d[s] = 0;  // 起点s到达自身的距离为0
    c[s] = 0;  // 起点s到达自身的花费为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;  // 找不到小于INF的d[u] 说明剩下的顶点和起点不连通
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {   // 以u为中介能令d[v]变小
                    d[v] = d[u] + G[u][v];     // 优化d[v]
                    c[v] = c[u] + cost[u][v];  // 优化c[v]
                    pre[v] = u;                // 令v的前驱为u
                } else if (d[u] + G[u][v] == d[v]) {  // 找到一条相同长度的路径
                    if (c[u] + cost[u][v] < c[v]) {  // 以u为中介时花费c[v]更小
                        c[v] = c[u] + cost[u][v];  // 优化c[v]
                        pre[v] = u;                // 令v的前驱为u
                    }
                }
            }
        }
    }
}

void DFS(int v) {  // 打印路径
    if (v == st) {
        cout << v << " ";
        return;
    }
    DFS(pre[v]);
    cout << v << " ";
}
int main() {
    cin >> n >> m >> st >> ed;
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);  // 初始化图G
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cin >> G[u][v] >> cost[u][v];
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    cout << d[ed] << " " << c[ed];  // 最短距离和最短路径下的最小花费
    return 0;
}