/*给出一棵二叉搜索树（给出每个结点的左右孩子），且已知根结点为0，给出应该插入这个二叉搜索树的数值，求这棵二叉树的层序遍历*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, cnt, b[100], maxLevel;
struct node {
    int data, l, r;  // 结点数据，左孩子结点索引，右孩子结点索引
} a[110];

vector<int> v[100];  // 存放二叉树的层序遍历结果，v[i]表示第i层的结点索引

// 深度优先搜索函数，用于将给定的数值插入二叉搜索树
void dfs(int root, int level) {
    maxLevel = max(level, maxLevel);  // 记录最大的层数
    if (a[root].l != -1) {
        dfs(a[root].l, level + 1);  // 递归遍历左子树
    }
    a[root].data = b[cnt++];  // 将排序后的数值赋值给当前结点
    if (a[root].r != -1) {
        dfs(a[root].r, level + 1);  // 递归遍历右子树
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;  // 输入二叉树的结点的左右孩子索引
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];  // 输入应该插入二叉搜索树的数值
    }
    sort(b, b + n);  // 将数值进行排序
    dfs(0, 0);  // 从根结点开始深度优先搜索，将排序后的数值插入二叉搜索树

    v[0].push_back(0);  // 将根结点的索引加入到层序遍历结果中

    // 层序遍历
    for (int i = 0; i <= maxLevel; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i != 0) {
                cout << " ";  // 输出每个数值之间的空格
            }
            cout << a[v[i][j]].data;  // 输出当前层的数值
            if (a[v[i][j]].l != -1) {
                v[i + 1].push_back(
                    a[v[i][j]].l);  // 将左孩子结点索引加入到下一层的遍历结果中
            }
            if (a[v[i][j]].r != -1) {
                v[i + 1].push_back(
                    a[v[i][j]].r);  // 将右孩子结点索引加入到下一层的遍历结果中
            }
        }
    }
    return 0;
}
