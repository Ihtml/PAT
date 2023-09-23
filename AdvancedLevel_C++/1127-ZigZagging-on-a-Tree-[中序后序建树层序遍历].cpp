/*给出一个树的中序和后序遍历结果，求它的Z字型层序遍历，也就是偶数层从右往左，奇数层从左往右遍历*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> in, post, result[35];
struct node {
    int index, depth;
};
int main() {
    cin >> n;
    in.resize(n + 1), post.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    return 0;
}