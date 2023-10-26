/*给出二叉树的前序和中序序列，给出后序序列的第一个元素*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
// 递归构建后序序列的函数
void postOrder(int prel, int inl, int inr) {
    if (inl > inr || flag == true)
        return;  // 递归终止条件，中序序列中左边界大于右边界或者标记已找到后序序列的第一个元素则返回

    int i = inl;
    while (in[i] != pre[prel])
        i++;  // 在中序序列中找到根节点的位置

    postOrder(prel + 1, inl, i - 1);            // 递归构建左子树
    postOrder(prel + i - inl + 1, i + 1, inr);  // 递归构建右子树

    if (flag == false) {
        printf("%d", in[i]);  // 找到后序序列的第一个元素并输出
        flag = true;          // 标记已找到
    }
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    postOrder(0, 0, n - 1);
    return 0;
}