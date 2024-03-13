#include <algorithm>
#include <iostream>
using namespace std;
const int MAXV = 510;       // 最大顶点数
const int INF = 100000000;  // 无穷大

int n, m, G[MAXV][MAXV];  // n为顶点数，m为边数,G为距离矩阵，
int d[MAXV];              // d[]记录最短距离
bool vis[MAXV] = {false};  // vis[i]==true表示顶点i已访问，初值均为false

void Dijkstra(int s) {  // s为起点
    fill(d, d + MAXV, INF);
    d[s] = 0;  // 起点s到达自身的距离为0
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
                if (d[u] + G[u][v] < d[v]) {  // 以u为中介能令d[v]变小
                    d[v] = d[u] + G[u][v];    // 优化d[v]
                }
            }
        }
    }
}
int prim() {  // 默认0号为初始点，函数返回最小生成树的边权之和
    fill(d, d + MAXV * MAXV, INF);
    d[0] = 0;     // 只有0号顶点到集合s的距离为0，其余全为INF
    int ans = 0;  // 存放最小生成树的边权之和
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;  // u使d[u]最小，MIN存放改最小的d[u]
        for (int j = 0; j < n; j++) {  // 找到未访问的顶点中d[]最小的
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        ans += d[u];  // 将与集合s距离最近的边加入最小生成树
        for (int v = 0; v < n; v++) {  // 以u为中介点可以使v离集合s更近
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];  // 将G[u][v]赋值给d[v]
            }
        }
    }
    return ans;  // 返回最小生成树的边权之和
}
int main() {
    cin >> n >> m;
    int u, v, w;
    fill(G[0], G[0] + MAXV * MAXV, INF);  // 初始化图G
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        G[v][u] = G[u][v] = w;
    }
    int ans = prim();
    cout << ans;
    return 0;
}