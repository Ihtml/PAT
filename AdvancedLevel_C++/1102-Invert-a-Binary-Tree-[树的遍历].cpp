// 反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序遍历和反转后的树的中序遍历
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, l, r, index, level;  // 每个结点的id, 左右结点,下标值，和当前层数
} a[100];
vector<node> v1;
// 已知根结点，用递归的方法可以把中序遍历的结果push_back到数组v1里面，
// 直接输出就是中序，排序输出就是层序（排序方式，
void dfs(int root, int index, int level) {
    if (a[root].r != -1) {
        dfs(a[root].r, index * 2 + 2, level + 1);
    }
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) {
        dfs(a[root].l, index * 2 + 1, level + 1);
    }
}
// 层数小的排前面，相同层数时，index大的排前面）
bool cmp(node a, node b) {
    if (a.level != b.level) {
        return a.level < b.level;
    }
    return a.index > b.index;
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
    // 根结点是所有左右结点中没有出现的那个结点
    while (have[root] == 1) {
        root++;
    }
    dfs(root, 0, 0);
    // 创建了一个名为v2的新向量容器，并将v1中的所有元素复制到v2中。是深拷贝
    vector<node> v2(v1);
    sort(v2.begin(), v2.end(), cmp);
    return 0;
}
