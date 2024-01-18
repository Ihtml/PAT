// 笛卡尔树，一系列不同数字构成的二叉树。树是堆排序的，中序遍历返回原始序列。
// 在小顶堆中，数值最小的那个元素为根结点，对于其任何子树也一样。
// 只要在中序遍历中找到最小的那个数作为当前的根结点，左边的所有数都归左子树，右边所有数都归右子树。
// 将根结点的序号设为1，左孩子的序号为它的两倍，右孩子的序号为它的两倍 + 1，
// 最后根据序号顺序输出ans即为层序遍历的顺序
#include <iostream>
#include <map>
using namespace std;
int n, In[32];
map<int, int> ans;
void deal(int index, int L, int R) {
    if (L > R)
        return;
    int pos = L;
    for (int i = L + 1; i <= R; i++) {
        if (In[i] < In[pos]) {
            pos = i;
        }
    }
    ans[index] = In[pos];
    deal(index << 1, L, pos - 1);
    deal(index << 1 | 1, pos + 1, R);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> In[i];
    }
    return 0;
}
