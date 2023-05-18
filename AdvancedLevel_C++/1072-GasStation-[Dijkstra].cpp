/*
从m个加油站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内。
如果有很多个最远的加油站，输出距离所有居民区距离平均值最小的那个。
如果平均值还是一样，就输出按照顺序排列加油站编号最小的那个。
*/
#include <limits>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 999999999, N = 1020;
int n, m, k, ds, station;
int e[N][N], dis[N];
bool visit[N];
int main() {
    fill(e[0], e[0] + N * N, inf);
    for (int i = 0; i < N; i++)
        e[i][i] = 0;
    fill(dis, dis + N, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string s, t;
    for (int i = 0; i < k; i++) {
        int tempdis;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = min(tempdis, e[a][b]);
        // 两点之间可能有多条路，只存储距离最短的路。
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for (int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + N, inf);
        fill(visit, visit + N, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for (int j = 1; j <= n + m; j++) {
                if (visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1)
                break;
            visit[u] = true;
            for (int v = 1; v <= n + m; v++) {
                if (visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] > ds) {
                mindis = -1;
                break;
            }
            if (dis[i] < mindis)
                mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1)
            continue;
        aver = aver / n;
        if (mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if (mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if (ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    return 0;
}