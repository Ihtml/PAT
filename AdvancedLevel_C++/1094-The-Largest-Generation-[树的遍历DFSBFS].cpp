#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);  // 孩子结点
        }
    }
    // dfs
    return 0;
}