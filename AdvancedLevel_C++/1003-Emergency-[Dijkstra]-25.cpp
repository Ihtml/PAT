#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, m, c1, c2, a, b, c;
    const int inf = 99999999;
    int weight[510], e[510][510], dis[510], num[510], w[510];
    bool visit[510];
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[i];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
    }
    
    return 0;
}