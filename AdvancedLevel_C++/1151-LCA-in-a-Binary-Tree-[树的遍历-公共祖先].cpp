// 给出中序序列和先序序列，再给出两个点，求这两个点的最近公共祖先

#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> pos;
vector<int> in, pre;
int main(){
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    in.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);
    return 0;
}