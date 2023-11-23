// 给一个有向图，判断给定序列是否是拓扑序列
// 用邻接表v存储这个有向图，并将每个节点的入度保存在in数组中。对每一个要判断是否是拓扑序列的结点遍历，
// 如果当前结点的入度不为0则表示不是拓扑序列，每次选中某个点后要将它所指向的所有结点的入度 - 1
// 最后根据是否出现过入度不为0的点决定是否要输出当前的编号i,flag是用来判断之前是否输出过现在是否要输出空格的
// judge是用来判断是否是拓扑序列
#include <iostream>
#include <vector>
    using namespace std;
int main() {
    int n, m, a, b, k, flag = 0, in[1010];
    vector<int> v[1010];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }
    return 0;
}