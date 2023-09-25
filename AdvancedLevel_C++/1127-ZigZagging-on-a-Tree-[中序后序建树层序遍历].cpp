/*给出一个树的中序和后序遍历结果，求它的Z字型层序遍历，也就是偶数层从右往左，奇数层从左往右遍历*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, tree[35][2], root;
vector<int> in, post, result[35];
struct node {
    int index, depth;
};
// 通过后序和中序遍历构建树
void dfs(int& index, int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight)
        return;  // 递归终止条件，处理完所有节点

    index = postRight;  // 当前节点为后序遍历最后一个节点
    int i = 0;
    while (in[i] != post[postRight])
        i++;  // 在中序遍历中找到当前根节点的位置

    // 递归构建左子树
    dfs(tree[index][0], inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);

    // 递归构建右子树
    dfs(tree[index][1], i + 1, inRight, postLeft + (i - inLeft), postRight - 1);
}
// 层序遍历树，按层存储结果
void bfs() {
    queue<node> q;
    q.push(node{root, 0}); // 根节点入队，初始深度为0

    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        result[temp.depth].push_back(post[temp.index]); // 将当前节点的值存入对应深度的结果

        // 左子树入队
        if (tree[temp.index][0] != 0)
            q.push(node{tree[temp.index][0], temp.depth + 1});

        // 右子树入队
        if (tree[temp.index][1] != 0)
            q.push(node{tree[temp.index][1], temp.depth + 1});
    }
}

int main() {
    cin >> n;
    in.resize(n + 1), post.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    return 0;
}