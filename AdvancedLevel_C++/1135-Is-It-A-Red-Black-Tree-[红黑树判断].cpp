/*给一棵二叉搜索树的前序遍历，判断它是否为红黑树，是输出Yes，否则输出No。*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

// 定义二叉树结构
struct node {
    int val;
    struct node *left, *right;
};

// 递归构建二叉搜索树
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

// 判断是否满足红黑树性质1：每个节点是红色或黑色
bool judge1(node* root) {
    if (root == NULL)
        return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0)
            return false;
        if (root->right != NULL && root->right->val < 0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}

// 获取以当前节点为根的子树的黑色节点数目
int getNum(node* root) {
    if (root == NULL)
        return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

// 判断是否满足红黑树性质2：根节点是黑色
bool judge2(node* root) {
    if (root == NULL)
        return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if (l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    int k, n;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node* root = NULL;

        // 读取输入数据，构建二叉搜索树
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }

        // 判断是否满足红黑树性质
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}