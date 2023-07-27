/*
提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。
求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth) {
    if (mindepth < depth) {
        return;
    }
    if (v[index].size() == 0) {
        if (mindepth == depth) {
            minnum++;
        } else if (mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
    }
    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main() {
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }

    return 0;
}