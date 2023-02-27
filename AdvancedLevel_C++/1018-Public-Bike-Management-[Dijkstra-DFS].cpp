#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;  // 每个点最大容量cmax  点的数量n 问题点sp  边数m
int minNeed = inf, minBack = inf;  // 最小需求量和最小回收量初始化为无穷大
int e[510][510], dis[510],
    weight[510];  // 图的邻接矩阵e，距离数组dis，每个点的权值weight
bool visit[510];             // 记录每个点是否被访问过
vector<int> pre[510];        // 记录每个点的前驱节点
vector<int> path, temppath;  // 最终路径path，临时路径temppath

// 深度优先遍历，寻找从源点到问题点的路径
void dfs(int v) {
    temppath.push_back(v);  // 将当前点添加到临时路径中
    if (v == 0) {  // 如果当前点是源点，遍历完成，计算需求量和回收量
        int need = 0, back = 0;
        for (int i = temppath.size() - 1; i >= 0; i--) { // 从后往前遍历临时路径
            int id = temppath[i];  // 当前节点的编号
            if (weight[id] > 0) {  // 如果当前节点的权值为正数，表示是回收点
                back += weight[id];
            } else {  // 否则为供应点
                if (back > (0 - weight[id])) { // 如果回收量大于需求量，则剩余的可回收量减少
                    back += weight[id];
                } else {  // 否则回收量不够，需要从其他点获取
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if (need < minNeed) {  // 更新最小需求量和最小回收量以及路径
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if (need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();  // 回溯，将当前点从临时路径中删除
        return;
    }
    // 遍历当前节点的前驱节点
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    // 读入每个点的自行车数，计算出需要/多余的自行车数
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        // 在未确定最短距离的点中，选取距离最短的点
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
        // 更新与当前点相邻的点的距离
        for (int v = 0; v <= n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    // 更新最短距离
                    dis[v] = dis[u] + e[u][v];
                    // 清空v的前驱节点集合
                    pre[v].clear();
                    // 将u加入v的前驱节点集合中
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]) {
                    // 将u加入v的前驱节点集合中
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for (int i = path.size() - 2; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d", minBack);
    return 0;
}