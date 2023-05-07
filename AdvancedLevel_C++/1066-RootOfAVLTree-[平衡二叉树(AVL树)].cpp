/*
给出一系列输入，输出AVL树根节点的值
*/
#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateLeft(node *root){
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node *rotateRight(node *root){
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateLeftRight(node *root){
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node *rotateRightLeft(node *root){
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
int main() {
    int n, val;
    cin >> n;
    node *root = NULL;
    return 0;
}