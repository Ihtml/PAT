// 判断给出的路径是否是Dijkstra最短路径
#include <climits>   // 使用INT_MAX要引用这个头文件
#include <iostream>
#include <vector>
using namespace std;
int V, E, K, Start, End, a, b, c, d, flag;
vector<vector<int>> Edge(1002, vector<int>(1002));
vector<int> Distance(1002), visited(1002);
void deal(int x, int index, vector<int> Path) {
    for (int k = 1; k <= V; k++) {
        int Min = INT_MAX, now = Path[index];
        for (int i = 1; i <= V; i++) {
            if (Distance[i] != INT_MAX && !visited[i] && Distance[i] <= Min) {
                if (Distance[i] < Min) {
                    flag = (i == now) ? 1 : 0;
                } else if (Distance[i] == Min) {
                    if (i == now) {
                        flag = 1;
                    }
                }
                Min = Distance[i];
            }
        }
        if (!flag)
            return;
        index++;
        if (index > V)
            return;
        visited[now] = 1;
        for (int i = 1; i <= V; i++) {
            if (!visited[i] && Distance[i] > Distance[now] + Edge[now][i] &&
                Edge[now][i] != 0) {
                Distance[i] = Distance[now] + Edge[now][i];
            }
        }
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> d;
        Edge[a][b] = Edge[b][a] = d;
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        vector<int> Path(V);
        flag = 1;
        fill(visited.begin(), visited.end(), 0);
        fill(Distance.begin(), Distance.end(), INT_MAX);
        for (int j = 0; j < V; j++) {
            cin >> Path[j];
        }
        Start = Path[0], End = Path[V - 1];
        Distance[Start] = 0;
        deal(Start, 0, Path);
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}