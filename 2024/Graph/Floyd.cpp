#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 100000000;
const int MAXV = 200;  // MAXV为最大顶点数
int n, m;              // n为顶点数 m为边数
int dis[MAXV][MAXV];   // dis[i][j]表示顶点i和顶点j的最短距离

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF &&
                    dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];  // 找到更短的路径
                }
            }
        }
    }
}

int main() {
    return 0;
}