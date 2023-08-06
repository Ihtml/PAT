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
int main() {
    int n, root=0, have[100] = {0};
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
    cin >> n;
}