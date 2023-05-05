/*
给一串构成树的序列，已知该树是完全二叉搜索树，求它的层序遍历的序列
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int In[1010], lel[1010], n, t = 0;
void inOrder(int root) {
    if (root >= n)
        return;
    inOrder(root * 2 + 1);
    lel[root] = In[t++];
    inOrder(root * 2 + 2);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &In[i]);
    }
    sort(In, In + n);
    inOrder(0);
    printf("%d", lel[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", lel[i]);
    }
    return 0;
}

vector<int> in, level;
void levelorder(int start, int end, int index) {
    if (start > end) {
        return;
    }
    int n = end - start + 1;
    int l = log(n + 1) / log(2);  // ceil(log2(n+1))  除了最后一层的层数
    int leave = n - (pow(2, l) - 1);  // 最后一层的叶子节点数
    int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave);
    // pow(2, l - 1) - 1是除了root结点所在层和最后一层外，左子树的结点个数
    //  pow(2, l - 1) 是l+1 层最多拥有的属于根结点左子树的结点个数
    // min(pow(2, l - 1),
    // leave)是最后⼀个结点真正拥有的属于根结点左子树上的结点个数
    level[index] = in[root];
    levelorder(start, root - 1, 2 * index + 1);
    levelorder(root + 1, end, 2 * index + 2);
}
int main0() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in.begin(), in.end());  // BST按从小到大排序就是中序遍历
    levelorder(0, n - 1, 0);
    printf("%d", level[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", level[i]);
    }
    return 0;
}