#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int index, value;
};
bool cmp(node a, node b) {
    return a.index < b.index;
}
vector<int> post, in;
vector<node> ans;
// root：当前子树的根节点在 post 序列中的下标
// start：当前子树在 in 序列中的起始下标
// end：当前子树在 in 序列中的结束下标
// index：当前子树在 ans数组中的起始编号
// 函数将 post 序列的最后一个元素作为根节点，然后在 in序列中找到根节点的位置，
// 接着将 in序列分成左右两个子序列，分别对应于左子树和右子树，
// 然后分别递归构建左子树和右子树，并在ans 数组中保存节点的编号和值
// 后序是左右根  中序是左根右  先序是根左右
void pre(int root, int start, int end, int index) {
    if (start > end) {
        return;
    }
    int i = start;
    while (i < end && in[i] != post[root]) {
        i++;
    }
    // 方式一：
    // node a;
    // a.index = index;
    // a.value = post[root];
    // ans.push_back(a);

    // 方式二：C++11以下低版本编译器不支持使用花括号初始化方式。可以将这一行代码改成方式三使用构造函数进行初始化：
    // ans.push_back({index, post[root]});

    // 方式三：
    ans.push_back(node{index, post[root]});
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);  // 左子树
    pre(root - 1, i + 1, end, 2 * index + 2);              // 右子树
}
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    pre(n - 1, 0, n - 1, 0);            // 输出先序的递归
    sort(ans.begin(), ans.end(), cmp);  // vector中按照 index排序就是层序遍历的顺序
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i].value;
    }
    return 0;
}