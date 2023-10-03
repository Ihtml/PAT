/*找出一条路线，使得对任何给定的起点和终点，可以找出中途经停站最少的路线；如果经停站一样多，则取需要换乘线路次数最少的路线*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
vector<int> path, tempPath;
int visit[10000], minCnt, minTransfer, start, end1;
int main() {
    int n, m, k, pre, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> n >> pre;
        for (int j = 1; j < m; j++) {
            cin >> temp;
            v[pre].push_back(temp);
            v[temp].push_back(pre);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> start >> end1;
        minCnt = 9999, minTransfer = 9999;
        tempPath.clear();
    }

    return 0;
}