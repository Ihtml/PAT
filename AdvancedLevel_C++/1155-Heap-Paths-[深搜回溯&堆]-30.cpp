/*深度优先搜索（DFS）遍历二叉树，并判断二叉树是否为最小堆、最大堆或者既不是最小堆也不是最大堆。*/
#include <iostream>
#include <vector>
using namespace std;

int n, a[1005];
vector<int> v;

// 深度优先搜索遍历二叉树
void dfs(int idx) {
    // 如果当前节点是叶子节点，输出路径
    // 如果节点的左孩子和右孩子都越界了（即超过了二叉树的总节点数
    // n），那么当前节点就是叶子节点
    if (idx * 2 > n && idx * 2 + 1 > n) {
        if (idx <= n) {
            for (int i = 0; i < v.size(); i++) {
                printf("%d%s", v[i], i == v.size() - 1 ? "\n" : " ");
            }
        }
    } else {
        // 非叶子节点，分别遍历左右子树
        v.push_back(a[idx * 2 + 1]);
        dfs(idx * 2 + 1);
        v.pop_back();
        v.push_back(a[idx * 2]);
        dfs(idx * 2);
        v.pop_back();
    }
}

int main() {
    scanf("%d", &n);

    // 输入二叉树节点值
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 初始化遍历路径，从根节点开始深度优先搜索
    v.push_back(a[1]);
    dfs(1);

    // 判断堆的性质
    int minh = 1, maxh = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i / 2]) {
            minh = 0;
        } else {
            maxh = 0;
        }
    }

    // 输出结果
    if (maxh) {
        printf("Max Heap");
    } else {
        printf(minh ? "Min Heap" : "Not Heap");
    }

    return 0;
}
