#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k, node, c;
    vector<int> v[100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    return 0;
}