// 反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序遍历和反转后的树的中序遍历
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, l, r, index, level;  // 每个结点的id, 左右结点,下标值，和当前层数
} a[100];
vector<node> v1;
void dfs(int root, int index, int level) {
    if (a[root].r != -1) {
        dfs(a[root].r, index * 2 + 2, level + 1);
    }
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) {
        dfs(a[root].l, index * 2 + 1, level + 1);
    }
}
int main() {
    int n, root = 0, have[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        } else {
            a[i].l = -1;
        }
        if (r != "-") {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        } else {
            a[i].r = -1;
        }
    }
    while (have[root] == 1) {
        root++;
    }
    dfs(root, 0, 0);
    return 0;
}
