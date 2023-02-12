#include <algorithm>
#include <cstdio>
using namespace std;
bool visit[1010];
int n, v[1010][1010];
void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++) {
        fill(visit, visit + 100, false);
        scanf("%d", &a);
    }
    return 0;
}