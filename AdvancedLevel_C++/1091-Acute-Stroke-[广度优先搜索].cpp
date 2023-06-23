/*
Q:给定一个三维数组，0表示正常1表示有肿瘤，肿瘤块的大小大于等于t才算作是肿瘤，让计算所有满足肿瘤块的大小
A:三维的广度优先搜索～XYZ三个数组判断方向，对每一个点广度优先累计肿瘤块的大小，如果大于等于t就把结果累加。
用visit数组标记当前的点有没有被访问过，被访问过的结点是不会再访问的。
judge判断是否超过了边界，或者是否当前结点为0不是肿瘤
*/
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];
bool judge(int x, int y, int z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
        return false;
    if (arr[x][y][z] == 0 || visit[x][y][z] == true)
        return false;
    return true;
}
int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    queue<node> q;
    q.push(temp);
    visit[x][y][z] = true;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if (judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if (cnt >= t) {
        return cnt;
    } else {
        return 0;
    }
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &arr[j][k][i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[j][k][i] == 1 && visit[j][k][i] == false) {
                    ans += bfs(j, k, i);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}