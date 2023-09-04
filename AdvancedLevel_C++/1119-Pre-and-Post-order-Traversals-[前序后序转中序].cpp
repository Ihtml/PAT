/*给出一棵树的结点个数n，以及它的前序遍历和后序遍历，输出它的中序遍历，
如果中序遍历不唯一就输出No，且输出其中一个中序即可，如果中序遍历唯一就输出Yes，并输出它的中序*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool isUnique = true;
void getIn(int preLeft,int preRight,int postLeft, int postRight){
    if (preLeft == preRight) {
        // 如果前序和后序遍历序列只有一个元素，直接加入到中序序列
        in.push_back(pre[preLeft]);
        return;
    }
    // 如果前序遍历序列的第一个元素等于后序遍历序列的最后一个元素
    if (pre[preLeft] == post[postRight]) {
        // 在前序遍历中找到与后序遍历倒数第二个元素相等的元素
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight - 1]) {
            i++;
        }
        // 如果找到的元素数量大于1，说明左子树不为空
        if (i - preLeft > 1) {
            // 递归构建左子树的中序遍历
            getIn(preLeft + 1, i - 1, postLeft,
                  postLeft + (i - preLeft - 1) - 1);
        } else {
            // 如果左子树为空，则不是唯一的中序遍历
            isUnique = false;
        }
        // 加入当前节点的值到中序遍历序列
        in.push_back(post[postRight]);
        // 递归构建右子树的中序遍历
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}
int main() {
    int n;
    cin >> n;
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    getIn(0, n - 1, 0, n - 1);
    cout << (isUnique == true ? "Yes" : "No") << in[0];

    return 0;
}