// 给出一棵二叉搜索树的前序遍历，问结点u和v的共同最低祖先是谁
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 使用 map 记录每个节点是否存在
map<int, bool> mp;

int main() {
    int m, n, u, v, a;

    // 输入查询次数和节点数量
    scanf("%d %d", &m, &n);

    // 保存前序遍历结果
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;  // 标记节点存在
    }

    // 处理每一次查询
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // 寻找最低祖先
        for (int j = 0; j < n; j++) {
            a = pre[j];
            // 先序遍历的二叉搜索树中，根据“根左右”原则，如果 a 在 u 和 v
            // 之间，则 a 就是最低祖先
            if ((a >= u && a <= v) || (a >= v && a <= u))
                break;
        }

        // 输出结果
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }

    return 0;
}
