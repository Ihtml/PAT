/*
Q:有N个城市(编号为0~N-1)、M条道路(无向边)，开给出M条道路的距离属性与化费属性。现在给定起点S与终点D,求从起点到终点的最短路径、最短距离及花费。
注意如果有多条最短路径，则选择花费最小的那条。
A:
对使用Djjkstra +
DFS的写法，Dijkstra的部分可以直接把之前给出的模板写上。至于DFS部分，对当前得到的一条路径tempPath，
需要计算出该路径上的边权之和，然后令其与最小边权minCost进行比较，如果新路径的边权之和更小，则更新minCost和最优路径path,核
心代码如下。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 510;       // 最大顶点数
const int INF = 100000000;  // 无穷大

// n为顶点数，m为边数，st和ed分别为起点和终点
// G为距离矩阵， cost为花费矩阵
// d[]记录最短距离，c[]记录最小花费
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = {false};  // vis[i]==true表示顶点i已访问，初值均为false
vector<int> pre[MAXV];       // 前驱
vector<int> tempPath, path;  // 临时路径，最优路径

// Dijkstra模板
void Dijkstra(int s) {  // s为起点
   
}

void DFS(int v) {  // 打印路径
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
    Dijkstra(st);                     // DFS算法入口
    DFS(ed);                          // 获取最优路径
    cout << d[ed] << " " << minCost;  // 最短距离和最短路径下的最小花费
    return 0;
}