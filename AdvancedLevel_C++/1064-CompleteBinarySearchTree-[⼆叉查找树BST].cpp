/*
给一串构成树的序列，已知该树是完全二叉搜索树，求它的层序遍历的序列
*/
#include <iostream>
#include <vector>
vector<int> in, level;
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in.begin(), in.end()); // BST按从小到大排序就是中序遍历
    return 0;
}