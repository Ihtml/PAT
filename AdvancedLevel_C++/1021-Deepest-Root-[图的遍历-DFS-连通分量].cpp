#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;
void dfs(int node, int height) {
    if (height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if (height == maxheight) {
        temp.push_back(node);
    }
    visit[node] = true;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == false) {
            dfs(v[node][i], height + 1);
        }
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0) {
                    s1 = temp[0];
                }
                for (int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }

    return 0;
}