#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];  // 邻接表表示图
int book[100],
    maxdepth = -1;  // book数组记录每层的节点数量，maxdepth记录树的深度

// 深度优先搜索
void dfs(int index, int depth) {
    if (v[index].size() == 0) {
        // 如果当前节点是叶子节点，更新book数组和maxdepth
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }

    // 遍历当前节点的子节点
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);

    // 构建图
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }

    // 从根节点开始深度优先搜索
    dfs(1, 0);

    // 输出结果
    printf("%d", book[0]);
    for (int i = 1; i <= maxdepth; i++) {
        printf(" %d", book[i]);
    }

    return 0;
}
