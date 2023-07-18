// 反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序遍历和反转后的树的中序遍历
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, l, r, index, level;
} a[100];
int main() {
    int n, root = 0, have[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
    }
    return 0;
}
