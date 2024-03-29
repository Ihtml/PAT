#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post;
bool isMirror;
/*
    8
  6   10
5  7 8   11
pre: 8 6 5 7 10 8 11
post: 5 7 6 8 11 10 8
*/
void getpost(int root, int tail) {
    if (root > tail) {
        return;
    }
    int i = root + 1, j = tail;
    if (!isMirror) {
        while (i <= tail && pre[root] > pre[i]) {
            i++;  // 根结点右子树的节点
        }
        while (j > root && pre[root] <= pre[j]) {
            j--;  // 根结点左子树的结点
        }
    } else {
        while (i <= tail && pre[root] <= pre[i]) {
            i++;
        }
        while (j > root && pre[root] > pre[j]) {
            j--;
        }
    }
    if (i - j != 1) {
        return;
    }
    getpost(root + 1, j);  // 遍历左子树
    getpost(i, tail);      // 遍历右子树
    post.push_back(pre[root]);
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    getpost(0, n - 1);
    if (post.size() != n) {
        isMirror = true;  // 假设为镜像
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", post[i]);
        }
    } else {
        printf("NO");
    }
    return 0;
}