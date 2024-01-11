#include <iostream>
#include <vector>
using namespace std;
struct node {
    int lchild, rchild;
    string data;
    node() { lchild = rchild = -1; }
} A[33];
void deal(int x) {  // 递归后序遍历
    cout << "(";
    int l = A[x].lchild, r = A[x].rchild;
    if (l != -1 && r != -1) {
        deal(l);
        deal(r);
    }
    cout << A[x].data;
    if (l == -1 && r != -1) {  // 处理只有右孩子的情况，即负数
        deal(r);
    }
    cout << ")";
}
int main() {
    int n, root = 1;
    vector<int> mark(33);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].data >> A[i].lchild >> A[i].rchild;
        if (A[i].lchild > 0) {
            mark[A[i].lchild] = 1;
        }
        if (A[i].rchild > 0) {
            mark[A[i].rchild] = 1;
        }
    }
    while (mark[root]) {  // 寻找根结点下标
        root++;
    }
    deal(root);
    return 0;
}