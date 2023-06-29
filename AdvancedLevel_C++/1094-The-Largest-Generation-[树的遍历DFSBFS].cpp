/*输入树的结点个数N，结点编号为1~N，非叶子结点个数M，然后输出M个非叶子结点格子的孩子结点的编号，
求结点个数最多的一层，
根结点的层号为1，输出该层的结点个数以及层号*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];  // 存储树的邻接表
int book[100];       // 记录每个层级的结点数量

void dfs(int index, int level) {
    book[level]++;  // 当前层级结点数量加1
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], level + 1);  // 递归遍历子结点，层级加1
    }
}

int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);  // 输入成员总数n和有孩子的结点个数m

    // 构建树的邻接表
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);  // 结点a的孩子结点为c
        }
    }

    dfs(1, 1);  // 从根结点1开始进行深度优先搜索，初始层级为1

    int maxnum = 0, maxlevel = 1;
    for (int i = 1; i < 100; i++) {
        if (book[i] > maxnum) {
            maxnum = book[i];  // 更新最大结点数量
            maxlevel = i;      // 更新对应的层级
        }
    }

    // dfs
    int level[100];
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        book[level[index]]++;
        for (int i = 0; i < v[index].size(); i++)
        {
            level[v[index][i]] = level[index] +1;
            q.push(v[index][i]);
        }
    }
    

    printf("%d %d", maxnum, maxlevel);  // 输出最大结点数量和对应的层级
    return 0;
}