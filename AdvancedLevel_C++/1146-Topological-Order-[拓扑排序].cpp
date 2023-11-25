// 给一个有向图，判断给定序列是否是拓扑序列
// 用邻接表v存储这个有向图，并将每个节点的入度保存在in数组中。对每一个要判断是否是拓扑序列的结点遍历，
// 如果当前结点的入度不为0则表示不是拓扑序列，每次选中某个点后要将它所指向的所有结点的入度
// - 1
// 最后根据是否出现过入度不为0的点决定是否要输出当前的编号i,flag是用来判断之前是否输出过现在是否要输出空格的
// judge是用来判断是否是拓扑序列
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b, k, flag = 0, in[1010];
    vector<int> v[1010];

    // 输入节点数量和边的数量
    scanf("%d %d", &n, &m);

    // 构建图，记录每个节点的入度
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }

    // 输入测试的次数
    scanf("%d", &k);

    // 处理每次测试
    for (int i = 0; i < k; i++) {
        int judge = 1;

        // 复制入度数组，用于测试
        // 将数组 in 从指针 in 开始的位置拷贝到指针 in + n + 1
        // 结束的位置，构造一个新的 vector<int> 对象。
        vector<int> tin(in, in + n + 1);

        // 输入测试序列
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);

            // 如果入度不为0，说明有依赖关系，测试不通过
            if (tin[a] != 0)
                judge = 0;

            // 更新被依赖节点的入度
            for (int it : v[a])
                tin[it]--;
        }

        // 输出测试结果
        if (judge == 1)
            continue;

        // 格式化输出
        printf("%s%d", flag == 1 ? " " : "", i);
        flag = 1;
    }

    return 0;
}
