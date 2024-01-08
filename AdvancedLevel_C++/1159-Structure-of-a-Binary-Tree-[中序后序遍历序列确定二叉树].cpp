#include <iostream>
using namespace std;
struct node {
    int lchild, rchild, parent, level;
    node() { lchild = rchild = parent = -1; }
} Tree[1002];
int n, m, a, b, root, flag, notFull;
int In[32], Post[32];
string t;
// 根据二叉树的后序和中序遍历序列确定二叉树的结构
int deal(int R, int start, int end, int Pa) {
    if (start > end) {
        return -1;
    }
    int i = start;
    while (i < end && In[i] != Post[R]) {
        i++;
    }
    Tree[Post[R]].parent = Pa;
    Tree[Post[R]].level = Tree[Pa].level + 1;
    // 处理左子树
    Tree[Post[R]].lchild = deal(R - 1 - end + i, start, i - 1, Post[R]);
    // 处理右子树
    Tree[Post[R]].rchild = deal(R - 1, i + 1, end, Post[R]);
    // 一个二叉树的任何一个节点，如果只包含0个或者2个子节点的话，那么这个二叉树即为
    // Full Binary Tree(英文语境下的满二叉树)
    if (Tree[Post[R]].lchild * Tree[Post[R]].rchild < 0) {
        notFull = 1;
    }
    return Post[R];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> In[i];
    }
    root = Post[n - 1];
    deal(n - 1, 0, n - 1, 1001);
    cin >> m;
    while (m--) {
        flag = 0;
        cin >> t;
        if (t == "It") {
            cin >> t >> t >> t >> t;
            if (notFull) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
            continue;
        }
        a = stoi(t);
        cin >> t;
        if (t == "is") {
            cin >> t >> t;
            if (t == "root") {
                if (a == root) {
                    flag = 1;
                }
            } else if (t == "parent") {
                cin >> t >> b;
                if (Tree[b].parent == a) {
                    flag = 1;
                }
            } else if (t == "left") {
                cin >> t >> t >> b;
                if (Tree[b].lchild == a) {
                    flag = 1;
                }
            } else {
                cin >> t >> t >> b;
                if (Tree[b].rchild == a) {
                    flag = 1;
                }
            }
        } else {
            cin >> b >> t >> t;
            if (t == "siblings") {
                if (Tree[a].parent == Tree[b].parent)
                    flag = 1;

            } else {
                cin >> t >> t >> t;
                if (Tree[a].level == Tree[b].level) {
                    flag = 1;
                }
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}