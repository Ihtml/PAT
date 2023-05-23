#include <iostream>
#include <vector>
using namespace std;
int n, m, l, k;
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
    return 0;
}