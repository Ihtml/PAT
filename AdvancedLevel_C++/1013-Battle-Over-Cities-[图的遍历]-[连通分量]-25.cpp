#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n, m, k, a, b, v[1010][1010];
    bool visit[1010];
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