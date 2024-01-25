#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int v, score, voucher;
    bool operator<(const node& x) const {
        if (score != x.score) {
            return score > x.score;
        } else {
            return voucher < x.voucher;
        }
    }
};
struct edge {
    int next, S, D;
};
vector<int> in(1003), in2(1003),
    last(1003);  // Last数组存储最短路中每个结点的前一个结点是什么
vector<edge> E[1003];
vector<pair<int, int>> Dis(1003, {INT_MAX, -1});  // 用1002当初始点
queue<int> Q;
int n, m, T1, T2, S, D, k;
// 用构造拓扑排序的方法判断一下图中是否存在环
bool hasCycle() {
    vector<int> S;
    while (Q.size()) {  // BFS
        int now = Q.front();
        Q.pop();
        S.push_back(now);
        for (auto it : E[now]) {
            in2[it.next]--;  // 将其所有能到达的结点的入度减1
            if (in2[it.next] == 0) {
                Q.push(it.next);
            }
        }
    }
    return S.size() == n;  // 如果全部都能拿到，则说明无环。
}
void dijkstra() {
    vector<int> vis(1003);
    priority_queue<node> pQ;  // 默认为最大堆
    pQ.push({1002, 0, 0});
    Dis[1002].first = Dis[1002].second = 0;
    while (pQ.size()) {
        node now = pQ.top();
        pQ.pop();
        if (vis[now.v]) {
            continue;
        }
        vis[now.v] = 1;
        Dis[now.v].first = now.score;
        Dis[now.v].second = now.voucher;
        for (auto it : E[now.v]) {
            if (vis[it.next]) {
                continue;
            }
            if (Dis[it.next].first > Dis[now.v].first + it.S ||
                ((Dis[it.next].first == Dis[now.v].first + it.S) &&
                 (Dis[it.next].second < Dis[now.v].second + it.D))) {
                Dis[it.next].first = Dis[now.v].first + it.S;
                Dis[it.next].second = Dis[now.v].second + it.D;
                last[it.next] = now.v;
                pQ.push({it.next, Dis[it.next].first, Dis[it.next].second});
            }
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> T1 >> T2 >> S >> D;
        E[T1].push_back({T2, S, D});
        in[T2]++, in2[T2]++;
    }
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            E[1002].push_back({i, 0, 0});
            Q.push(i);  // 将当前入度为0的结点存在队列里
        }
    }
    bool flag = hasCycle();
    dijkstra();
    cin >> k;
    cout << (flag ? "Okay.\n" : "Impossible.\n");
    for (int i = 1, q; i <= k; i++) {
        cin >> q;
        if (!in[q]) {
            cout << "You may take test " << q << " directly.\n";
        } else if (!flag) {
            cout << "Error.\n";
        } else {
            vector<int> path;
            int now = q;
            while (q != 1002) {
                path.push_back(q);
                q = last[q];
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                if (j)
                    cout << "->";
            }
            cout << "\n";
        }
    }
    return 0;
}