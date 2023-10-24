/*给出二叉树的前序和中序序列，给出后序序列的第一个元素*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    return 0;
}