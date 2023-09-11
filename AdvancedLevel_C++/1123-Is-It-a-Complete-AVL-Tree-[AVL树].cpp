/*构建一个AVL树，给出层序遍历序列，并判断是不是完全二叉树*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
int getHeight(node* tree) {
    if (tree == NULL) {
        return 0;
    }
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}
node* insert(node* tree, int val) {
    if (tree == NULL) {
        tree = new node();
        tree->val = val;
    } else if (tree->val > val) {
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        // todo
    } else {
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        // todo
    }
    return tree;
}
int main() {
    int n, temp;
    cin >> n;
    node* tree = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    return 0;
}