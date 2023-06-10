/*
Q:用栈的形式给出一棵二叉树的建立的顺序，求这棵二叉树的后序遍历
A:栈实现的是二叉树的中序遍历（左根右），而每次push入值的顺序是二叉树的前序遍历（根左右）所以该题可以用二叉树前序和中序转后序的方法做
*/
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> pre, in, post, value;
void postorder(int root, int start, int end) {
    if (start > end) {
        return;
    }
    int i = start;
    while (i < end && in[i] != pre[root]) {
        i++;  // 找到根节点在中序数组的位置
    }
    // 左右根
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);  // 将根节点添加到后序遍历结果中
}
int main() {
    int n;
    cin >> n;
    char str[5];
    stack<int> s;
    int key = 0;
    // (~scanf("%s", str)) EOF=-1 补码全是1 ~按位取反=0

    while (~scanf("%s", str)) {
        if (strlen(str) == 4) {
            // PUSH 操作
            int num;
            cin >> num;
            value.push_back(num);  // value-key 记录结点的值
            pre.push_back(key);    // 前序遍历中的根节点序列
            s.push(key++);
        } else {
            // POP操作
            in.push_back(s.top());  // 记录中序遍历中的根节点序列
            s.pop();
        }
    }
    postorder(0, 0, n - 1);  // 从根节点开始进行后序遍历
    cout << value[post[0]];
    for (int i = 1; i < n; i++) {
        cout << " " << value[post[i]];
    }
    return 0;
}