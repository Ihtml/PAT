#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, k;
const int inf = 99999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
map<string, int> m;
map<int, string> m2;
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    cin >> n >> k;
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for (int i = 0; i < n; i++) {
        cin >> s >> weight[i + 2];
        m[s] = i + 1;
        m2[i + 1] = s;
    }

    return 0;
}