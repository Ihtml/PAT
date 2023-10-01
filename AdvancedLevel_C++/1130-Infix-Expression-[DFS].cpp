/*给一个二叉树，输出中缀表达式，且加上括号表示运算的优先级*/
#include <iostream>
using namespace std;
// 定义树节点的结构
struct node {
    string data; // 存储节点的数据，可以是操作符或操作数
    int l, r;    // 左子树和右子树的索引
} a[100];

// 递归函数，用于生成中缀表达式
string dfs(int root) {
    // 如果节点没有左子树和右子树，说明它是叶子节点，直接返回其数据
    if (a[root].l == -1 && a[root].r == -1) {
        return a[root].data;
    }
    
    // 如果节点没有左子树但有右子树，将右子树递归生成的表达式加入括号
    if (a[root].l == -1 && a[root].r != -1) {
        return "(" + a[root].data + dfs(a[root].r) + ")";
    }
    
    // 如果节点既有左子树又有右子树，将左子树和右子树递归生成的表达式与节点数据用括号括起来
    if (a[root].l != -1 && a[root].r != -1) {
        return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
    }
}
int main() {
    int n, have[100] = {0}, root = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if (a[i].l != -1) {
            have[a[i].l] = 1;  // 有父结点
        }
        if (a[i].r != -1) {
            have[a[i].r] = 1;  // 有父结点
        }
    }
    while (have[root] == 1) {
        // 只有根节点没有父结点
        root++;  // 根据所有孩子结点编号寻找1～n中没有出现过的编号标记为root
    }
    string ans = dfs(root);
    if (ans[0] == '(')
        ans = ans.substr(1, ans.size() - 2);  // 把最外层括号去掉
    cout << ans;
    return 0;
}
