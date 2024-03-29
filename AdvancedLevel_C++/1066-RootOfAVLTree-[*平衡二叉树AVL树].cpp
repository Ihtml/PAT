/*
给出一系列输入，输出AVL树根节点的值
*/
#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node* rotateLeft(node* root) {
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* rotateRight(node* root) {
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* rotateLeftRight(node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node* rotateRightLeft(node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* insert(node* root, int val) {
    if (root == NULL) {
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            root = val < root->left->val ? rotateRight(root)
                                         : rotateLeftRight(root);
        }
    } else {
        root->right = insert(root->right, val);
        if (getHeight(root->left) - getHeight(root->right) == -2) {
            root = val > root->right->val ? rotateLeft(root)
                                          : rotateRightLeft(root);
        }
    }
    return root;
}
int main() {
    int n, val;
    cin >> n;
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    cout << root->val;
    return 0;
}