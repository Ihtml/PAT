/*Q:输出一个二叉搜索树的最后两层结点个数a和b，以及他们的和c：“a + b = c”*/
/*A:用链表存储，递归构建二叉搜索树，深度优先搜索，
传入的参数为结点和当前结点的深度depth，如果当前结点为NULL就更新最大深度maxdepth的值并return，
将每一层所对应的结点个数存储在数组num中，输出数组的最后两个的值*/
#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点结构体
struct node {
    int v;                      // 节点存储的值
    struct node *left, *right;  // 指向左右子节点的指针
};

// 函数用于向二叉搜索树中插入新的值
node* build(node* root, int v) {
    if (root == NULL) {  // 如果当前节点为空，则为其分配空间，并初始化
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    } else if (
        v <=
        root->v) {  // 如果插入的值小于或等于当前节点的值，则递归插入到左子树
        root->left = build(root->left, v);
    } else {  // 否则，递归插入到右子树
        root->right = build(root->right, v);
    }
    return root;  // 返回根节点的地址
}

vector<int> num(1000);  // 使用vector来存储每一层的节点数量
int maxdepth = -1;      // 记录树的最大深度

// 深度优先搜索（DFS）遍历二叉树，并统计每一层的节点数量
void dfs(node* root, int depth) {
    if (root == NULL) {  // 如果当前节点为空，则更新最大深度并返回
        maxdepth = max(depth, maxdepth);
        return;
    }
    num[depth]++;                 // 增加当前深度层的节点数量
    dfs(root->left, depth + 1);   // 递归遍历左子树
    dfs(root->right, depth + 1);  // 递归遍历右子树
}

int main() {
    int n, t;
    cin >> n;           // 输入节点总数
    node* root = NULL;  // 初始化根节点为NULL
    for (int i = 0; i < n; i++) {
        cin >> t;               // 输入每个节点的值
        root = build(root, t);  // 构建二叉搜索树
    }
    dfs(root, 0);  // 从根节点开始，深度为0，进行DFS遍历
    int n1 = num[maxdepth - 1], n2 = num[maxdepth - 2],
        n3 = n1 + n2;  // 计算最后两层的节点数量及其和
    cout << n1 << " + " << n2 << " = " << n3 << endl;  // 输出结果
    return 0;
}
