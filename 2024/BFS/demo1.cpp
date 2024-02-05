#include <iostream>
#include <queue>
using namespace std;
void BFS(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        // 取出队首元素pop
        // 访问队首元素top
        // 将队首元素出队
        // 将top的下一层结点中未曾入队的结点全部入队，并设置为已入队
    }
}
struct node {
    int data;
    node* lchild;
    node* rchild;
};

//  二叉树层序遍历
void LayerOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        cout << now->data;
        if (now->lchild != NULL) {
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            q.push(now->rchild);
        }
    }
}