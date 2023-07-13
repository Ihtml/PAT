/*给出一棵二叉搜索树（给出每个结点的左右孩子），且已知根结点为0，给出应该插入这个二叉搜索树的数值，求这棵二叉树的层序遍历*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, cnt, b[100], maxLevel;
struct node {
    int data, l, r;
} a[110];
vector<int> v[100];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    return 0;
}