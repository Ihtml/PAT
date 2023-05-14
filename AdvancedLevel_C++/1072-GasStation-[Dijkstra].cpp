#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int inf = INT_MAX, N = 1005;
int n, m, k, ds, station;
int e[N][N], dis[N];
bool visit[N];
int main() {
    fill(e[0], e[0] + N * N, inf);
    for (int i = 0; i < N; i++) {
        e[i][i] = 0;
    }
    fill(dis, dis + N, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string s, t;
    return 0;
}