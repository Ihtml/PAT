/*
Q:用栈的形式给出一棵二叉树的建立的顺序，求这棵二叉树的后序遍历
A:栈实现的是二叉树的中序遍历（左根右），而每次push入值的顺序是二叉树的前序遍历（根左右）所以该题可以用二叉树前序和中序转后序的方法做
*/
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
        i++;
    }
    // 左右根
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}
int main() {
    int n;
    cin >> n;
    string str;
    stack<int> s;
    int key = 0;
    // (~scanf("%s", str)) EOF=-1 补码全是1 ~按位取反=0
    while (scanf("%s", str) != EOF) {
        if (str.length() == 4) {
            // PUSH 操作
            int num;
            cin >> num;
            value.push_back(num);  // value-key
            pre.push_back(key);
            s.push(key++);
        } else {
            // POP操作
            in.push_back(s.top());
            s.pop();
        }
    }
    return 0;
}