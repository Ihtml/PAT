// 给出中序序列和先序序列，再给出两个点，求这两个点的最近公共祖先

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 使用map记录中序遍历的值和对应的索引
map<int, int> pos;
// 存储中序和先序遍历的数组
vector<int> in, pre;

// 寻找两个节点的最近公共祖先
void lca(int inl, int inr, int preRoot, int a, int b) {
    // 如果中序序列为空，直接返回，递归出口
    if (inl > inr)
        return;

    // 获取当前子树的根节点在中序序列中的位置
    int inRoot = pos[pre[preRoot]];
    int aIn = pos[a], bIn = pos[b];

    // 情况1：如果两个节点都在当前根节点的左子树
    if (aIn < inRoot && bIn < inRoot)
        lca(inl, inRoot - 1, preRoot + 1, a, b);
    // 情况2：如果两个节点分别在当前根节点的左右子树
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    // 情况3：如果两个节点都在当前根节点的右子树
    else if (aIn > inRoot && bIn > inRoot)
        lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), a, b);
    // 情况4：如果其中一个节点是当前根节点
    else if (aIn == inRoot)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
        printf("%d is an ancestor of %d.\n", b, a);
}


int main() {
    int m, n, a, b;
    // 读取节点数和查询次数
    scanf("%d %d", &m, &n);

    // 初始化数组大小
    in.resize(n + 1), pre.resize(n + 1);

    // 读取中序遍历序列，建立值到索引的映射关系
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }

    // 读取先序遍历序列
    for (int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);

    // 处理查询
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        // 如果a和b不在中序遍历序列中，输出错误信息
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }

    return 0;
}
