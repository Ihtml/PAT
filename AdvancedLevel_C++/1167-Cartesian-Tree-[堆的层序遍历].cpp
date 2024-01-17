// 笛卡尔树，一系列不同数字构成的二叉树。树是堆排序的，中序遍历返回原始序列。
#include <iostream>
#include <map>
using namespace std;
int n, In[32];
map<int, int> ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> In[i];
    }
    return 0;
}
