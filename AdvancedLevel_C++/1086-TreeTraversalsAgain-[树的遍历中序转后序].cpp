/*
Q:用栈的形式给出一棵二叉树的建立的顺序，求这棵二叉树的后序遍历
A:栈实现的是二叉树的中序遍历（左根右），而每次push入值的顺序是二叉树的前序遍历（根左右）所以该题可以用二叉树前序和中序转后序的方法做
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str;
    stack<int> s;
    while (scanf("%s", str) !=
           EOF) {  // (~scanf("%s", str)) EOF=-1 补码全是1 ~按位取反=0
        if (str.length() == 4) {
            // PUSH 操作
        } else {
            // POP操作
        }
    }
    return 0;
}