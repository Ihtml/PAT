// 二叉树的左视图是通过从左侧向右上方查看树而获得的结点列表。
#include <iostream>
#include <vector>
using namespace std;
vector<int> In(30), Pre(30), t(30);
void deal(int ins, int ine, int prerootindex, int level) {
    if (ins > ine) {
        return;
    }
    if (t[level] == 0) {
        t[level] = Pre[prerootindex];  // t存储某一层最左边的结点值
    }
    int pos = ins;
    while (In[pos] != Pre[prerootindex])
        pos++;
    deal(ins, pos - 1, prerootindex + 1, level + 1);              // 左子树
    deal(pos + 1, ine, prerootindex + 1 + pos - ins, level + 1);  // 右子树
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> In[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> Pre[i];
    }
    deal(1, n, 1, 1);
    for (int i = 1; t[i]; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << t[i];
    }
    return 0;
}