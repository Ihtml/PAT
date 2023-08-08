/*
Q:给出一个n表示有n个结点，这n个结点为0~n-1，给出这n个结点的左右孩子，求问这棵树是不是完全二叉树
A:完全二叉树最大的下标值 == 最大的节点数，不完全二叉树，最大的下标值 > 最大的节点数
*/
#include <iostream>
using namespace std;
struct node {
    int l, r;
} a[100];
int maxn = -1, ans;
// 深度优先搜索，计算最大下标值和对应的结点
void dfs(int root, int index) {
    // 如果当前的索引值比最大下标值还要大，则更新最大下标值和对应的结点
    if(index > maxn) {
        maxn = index;
        ans = root;
    }
    if(a[root].l != -1) dfs(a[root].l, index * 2);
    if(a[root].r != -1) dfs(a[root].r, index * 2 + 1);
}
int main() {
    int n, root=0, have[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    // 找到根节点
    while (have[root] != 0)
        root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}