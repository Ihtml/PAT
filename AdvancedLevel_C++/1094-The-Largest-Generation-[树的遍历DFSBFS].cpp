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
    return 0;
}