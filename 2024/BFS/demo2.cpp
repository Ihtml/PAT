#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    int layer;
    node* lchild;
    node* rchild;
};

//  二叉树层序遍历
void LayerOrder(node* root) {
    queue<node*> q;
    root->layer = 1;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        cout << now->data;
        if (now->lchild != NULL) {
            now->lchild->layer = now->layer + 1;
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild);
        }
    }
}