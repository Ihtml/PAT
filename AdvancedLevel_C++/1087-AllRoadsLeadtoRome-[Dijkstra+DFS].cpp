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
map<string, int> m;
map<int, string> m2;
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    cin >> n >> k;
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for (int i = 1; i < n; i++) {
        cin >> s >> weight[i + 2];
        m[s] = i + 1;
        m2[i + 1] = s;
    }
    string sa, sb;
    int temp;
    for (int i = 0; i < k; i++)
    {
        cin >> sa >> sb >> temp;
        e[m[sb]][m[sa]]  = e[m[sa]][m[sb]] = temp;
    }
    dis[1] = 0;
    // todo Dijkstra

    return 0;
}