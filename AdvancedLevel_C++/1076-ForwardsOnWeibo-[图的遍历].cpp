#include <iostream>
#include <vector>
using namespace std;
int n, m, l, k;
struct node {
    int id, layer;
};
int bfs(node tnode) {
    int cnt = 0;
    // todo
    return cnt;
}
vector<vector<int> > v;
int main() {
    scanf("%d %d", &n, &l);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            v[t].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for (int i = 0; i < k; i++) {
        scanf("%d", &tid);
        node tnode = {tid, 0};
        // printf("%d\n", bfs(tnode));
    }

    return 0;
}