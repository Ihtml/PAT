#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> v[n];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(i);
        v[b].push_back(i);
    }

    return 0;
}
