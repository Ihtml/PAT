/*
Q:有N个城市，M条无向边，从某个给定的起始城市出发，前往名为ROM的城市。
每个城市（除了起始城市）都有一个点权（称为幸福值），和边权（每条边所需的花费）。
求从起点到ROM所需要的最少花费，并输出其路径。
如果路径有多条，给出幸福值最大的那条。
如果仍然不唯一，选择路径上的城市平均幸福值最大的那条路径.
A:Dijkstra算出所有最短路径的路线pre二维数组，DFS求最大happiness的路径path，并求出路径条数，最大happiness，最大average
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, k;
const int inf = 99999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if (v == 1) {
        int value = 0;
        for (int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if (value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if (value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    cin >> n >> k;
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for (int i = 1; i < n; i++) {
        cin >> s >> weight[i + 1];
        m[s] = i + 1;
        m2[i + 1] = s;
    }
    string sa, sb;
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sb]][m[sa]] = e[m[sa]][m[sb]] = temp;
    }
    dis[1] = 0;
    // todo Dijkstra
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for (int j = 1; j <= n; j++) {
            if (visit[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
        for (int v = 1; v <= n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for (int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}