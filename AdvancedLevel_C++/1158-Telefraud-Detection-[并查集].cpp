#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k, n, m, c, r, d, record[1001][1001];
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> r >> d;
        record[c][r] += d;
    }

    return 0;
}