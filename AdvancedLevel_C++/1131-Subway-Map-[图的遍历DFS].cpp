/*找出一条路线，使得对任何给定的起点和终点，可以找出中途经停站最少的路线；如果经停站一样多，则取需要换乘线路次数最少的路线*/
/*在line[10000][10000]的数组中保存每两个相邻站中间的线路是几号线～
从头到尾遍历最终保存的路径，preLine为前一小段的线路编号，
如果当前的结点和前一个结点组成的这条路的线路编号和preLine不同，说明有一个换乘，就将cnt+1，
最后遍历完累加的cnt即是换乘的次数*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
vector<int> path, tempPath;
// minCnt-中途经停的最少的站; minTransfer-需要换乘的最小次数
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line; // 地铁线路信息映射表
void dfs(int node, int cnt){
    if (node == end1 &&
        (cnt < minCnt ||
         (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1)
        return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
// 通过检查路径上相邻站点所属的地铁线路是否不同来计算路径的换乘次数。
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i - 1] * 10000 + a[i]] != preLine) cnt++;
        preLine = line[a[i - 1] * 10000 + a[i]];
    }
    return cnt;
}
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
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
    }

    return 0;
}