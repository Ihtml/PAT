/*输入树的结点个数N，结点编号为1~N，非叶子结点个数M，然后输出M个非叶子结点格子的孩子结点的编号，
求结点个数最多的一层，
根结点的层号为1，输出该层的结点个数以及层号*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
int book[100];
void dfs(int index, int level) {
    book[level]++;
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], level + 1);
    }
}
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);  // n-成员总数 m-有孩子的结点的个数
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);  // 孩子结点
        }
    }
    dfs(1, 1);
    int maxnum = 0, maxlevel = 1;
    for (int i = 1; i < 100; i++) {
        if (book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}