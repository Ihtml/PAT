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
    cin >> n;
}