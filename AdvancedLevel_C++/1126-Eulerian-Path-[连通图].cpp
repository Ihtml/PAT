/*如果一个连通图的所有结点的度都是偶数，那么它就是Eulerian，
如果除了两个结点的度是奇数其他都是偶数，那么它就是Semi-Eulerian，
否则就是Non-Eulerian*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > v;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {
    visit[index] = true;
    cnt++;
    for (int i = 0; i < v[index].size(); i++) {
        if (visit[v[index][i]] == false) {
            dfs(v[index][i]);
        }
    }
}
int main() {
    int n, m, a, b, even = 0;
    cin >> n >> m;
    v.resize(n + 1);
    visit.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << v[i].size();
        if (v[i].size() % 2 == 0) {
            even++;
        }
    }
    printf("\n");
    dfs(1);
    if (even == n && cnt == n)
        printf("Eulerian");
    else if (even == n - 2 && cnt == n)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");
    return 0;
}
