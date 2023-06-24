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
int X[6] = {1, 0, 0, -1, 0, 0};  // x坐标的变化量
int Y[6] = {0, 1, 0, 0, -1, 0};  // y坐标的变化量
int Z[6] = {0, 0, 1, 0, 0, -1};  // z坐标的变化量
int arr[1300][130][80];          // 存储三维图像信息的数组
bool visit[1300][130][80];       // 记录结点是否被访问过
bool judge(int x, int y, int z) {
    // 判断结点是否合法
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
        return false;  // 结点超出边界，不合法
    if (arr[x][y][z] == 0 || visit[x][y][z] == true)
        return false;  // 结点为0或已经被访问过，不合法
    return true;       // 合法结点
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
        cnt++;  // 统计访问的结点数量
        for (int i = 0; i < 6; i++) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if (judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;  // 将合法结点标记为已访问
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);  // 将合法结点加入队列，继续搜索
            }
        }
    }
    if (cnt >= t) {
        return cnt;  // 如果符合要求的连通块的结点数量大于等于t，则返回该数量
    } else {
        return 0;  // 否则返回0，表示该连通块不符合要求
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
                    // 对每个未访问过的1结点进行BFS搜索，累加符合要求的连通块的数量
                    ans += bfs(j, k, i);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}