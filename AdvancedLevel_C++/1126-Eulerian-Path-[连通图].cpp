/*如果一个连通图的所有结点的度都是偶数，那么它就是Eulerian，
如果除了两个结点的度是奇数其他都是偶数，那么它就是Semi-Eulerian，
否则就是Non-Eulerian*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<bool> visit;
int cnt = 0;
int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n + 1);
    visit.resize(n + 1);
    return 0;
}
