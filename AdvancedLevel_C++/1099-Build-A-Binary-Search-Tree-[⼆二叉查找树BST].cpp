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
void dfs(int root, int level) {
    maxLevel = max(level, maxLevel);
    if (a[root].l != -1) {
        dfs(a[root].l, level + 1);
    }
    // a[root] = {b[cnt++], a[root].l, a[root].r};
    a[root].data = b[cnt++];
    if (a[root].r != -1) {
        dfs(a[root].r, level + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n);
    dfs(0, 0);
    v[0].push_back(0);
    // 层序遍历
    for (int i = 0; i <= maxLevel; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i != 0) {
                cout << " ";
            }
            cout << a[v[i][j]].data;
            if (a[v[i][j]].l != -1) {
                v[i + 1].push_back(a[v[i][j]].l);
            }
            if (a[v[i][j]].r != -1) {
                v[i + 1].push_back(a[v[i][j]].r);
            }
        }
    }
    return 0;
}