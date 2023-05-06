/*
给出一系列输入，输出AVL树根节点的值
*/
#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateleft(node *root){
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
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
    return 0;
}