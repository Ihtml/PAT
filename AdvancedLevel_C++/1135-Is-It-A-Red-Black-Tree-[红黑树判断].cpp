/*给一棵二叉搜索树的前序遍历，判断它是否为红黑树，是输出Yes，否则输出No。*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
struct node {
    int val;
    struct node *left, *right;
};
node* build(node* root, int v) {
    if (root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if (abs(v) <= abs(root->val)) {
        root->left = build(root->left, v);
    } else {
        root->right = build(root->right, v);
    }
    return root;
}

int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node* root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
    }
    return 0;
}