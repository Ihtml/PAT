#include <algorithm>
#include <cstdio>
using namespace std;
bool visit[1010];
int n, v[1010][1010];
void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
// 求去除了某个结点之后其他的图所拥有的联通分量数a
// 当a个相互分离的连通分量需要变为连通图的时候，只需要添加a-1个边
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k); // n个点 m条边 k个待检测点
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= n; j++) {
            // 在深度优先遍历的时候，对于所有未访问的结点进行遍历，得到所有连通分量个数
            if (visit[j] == false) {
                dfs(j);
                cnt++;  // 连通分量数
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}