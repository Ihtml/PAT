#include <iostream>
#include <map>
#include <vector>
using namespace std;
// n：区域总数 r:相邻区域数 k：物种数
int n, r, k, m, a, b;
int main() {
    cin >> n >> r >> k;
    vector<vector<int>> Graph(n + 1, vector<int>(n + 1));
    for (int i = 0; i < r; i++) {
        cin >> a >> b;
        Graph[a][b] = Graph[b][a] = 1;
    }
    for (cin >> m; m; m--) {
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            mp[a].push_back(i);  // 记录物种a生活在那几个区域
        }
        if (mp.size() > k) {
            cout << "Error: Too many species.\n";
        } else if (mp.size() < k) {
            cout << "Error: Too few species.\n";
        } else {
            int flag = 0;
            for (auto it : mp) {
                for (int i = 0; i < it.second.size(); i++) {
                    for (int j = i + 1; j < it.second.size(); j++) {
                        if (Graph[it.second[i]][it.second[j]]) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            cout << (flag ? "No\n" : "Yes\n");
        }
    }
    return 0;
}