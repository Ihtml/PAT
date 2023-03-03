#include <iostream>
#include <vector>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
vector<int> temp;
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    return 0;
}