/*Q:输出一个二叉搜索树的最后两层结点个数a和b，以及他们的和c：“a + b = c”*/
/*A:用链表存储，递归构建二叉搜索树，深度优先搜索，
传入的参数为结点和当前结点的深度depth，如果当前结点为NULL就更新最大深度maxdepth的值并return，
将每一层所对应的结点个数存储在数组num中，输出数组的最后两个的值*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
};
node* build(node* root, int v) {
    if (root = NULL) {
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    } else if (v <= root->v) {
        root->left = build(root->left, v);
    } else {
        root->right = build(root->right, v);
    }
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node* root, int depth) {
    if (root == NULL) {
        maxdepth = max(depth, maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int main() {
    int n, t;
    cin >> n;
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> t;
        root = build(root, t);
    }
    dfs(root, 0);
    return 0;
}