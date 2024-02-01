#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k, m, t;
const int maxn = 100;
string s;
vector<int> rect, prod, equa, indicesOfProduct;
struct Equation {
    vector<int> method[6];  // 每种产物最多5个方程，还有一种是自己生产自己
    int cnt;  // 生产方式的数目
    Equation() { cnt = 0; }
} record[maxn];
bool Reactant[maxn] = {false};  // 如果原材料i存在，Reactant[i] = true;
bool Used[maxn] = {false};  // 如果原材料i被使用过，Used[i] = true;
int getReactants(string s, vector<int>& v) {
    int i = 0;
    while (true) {  // 将原材料放入数组v
        v.push_back(stoi(s.substr(i, 2)));
        i += 3;
        if (s[i] == '+')
            i += 2;
        else {
            i += 3;
            break;
        }
    }
    return stoi(s.substr(i));  // 返回产物
}
bool cmp(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
}
vector<vector<int>> path, ans;  // path存可能的路径，ans存最终的结果
bool findAns = false;
// DFS函数定义：尝试通过深度优先搜索找到一系列化学反应的可能组合。
void DFS(int index, int m) {
    // 如果已经找到答案，则直接返回，避免不必要的搜索。
    if (findAns) {
        return;
    }
    // 如果已经为所有产品找到了反应路径，记录答案并标记找到答案。
    if (index == m && !findAns) {
        ans = path;
        findAns = true;
        return;
    }
    // 获取当前需要寻找反应路径的产品编号。
    int t = indicesOfProduct[index];
    // 遍历当前产品的所有可能反应方法。
    for (int i = 0; i < record[t].cnt; i++) {
        bool flag = true;  // 用于标记当前反应方法是否可行。
        // 检查当前反应方法的所有原料是否都满足条件（即存在且未被使用）。
        for (int j = 0; j < record[t].method[i].size(); j++) {
            if (!Reactant[record[t].method[i][j]] ||
                Used[record[t].method[i][j]]) {
                flag = false;
                goto OUT;  // 如果条件不满足，跳转到OUT标签，表示当前方法不可行。
            }
        }
    OUT:
        if (flag == false)
            continue;  // 如果当前反应方法不可行，继续检查下一个方法。
        // 如果找到一个可行的反应方法，标记所有使用的原料为已使用。
        for (int j = 0; j < record[t].method[i].size(); j++) {
            Used[record[t].method[i][j]] = true;
        }
        // 将当前反应方法加入到路径中，并继续搜索下一个产品的反应路径。
        path.push_back(record[t].method[i]);
        DFS(index + 1, m);
        // 搜索完成后，从路径中移除当前反应方法，并将原料标记为未使用，以便回溯。
        path.pop_back();
        for (int j = 0; j < record[t].method[i].size(); j++) {
            Used[record[t].method[i][j]] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        Reactant[t] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        indicesOfProduct.push_back(t);
        if (Reactant[t]) {
            record[t].method[record[t].cnt++].push_back(t);
        }
    }
    cin >> k;
    getchar();
    for (int i = 0; i < k; i++) {
        getline(cin, s);
        vector<int> v;  // 获取s中的所有原料
        t = getReactants(s, v);
        record[t].method[record[t].cnt++] = v;  // v加到产品t的生产方式中
    }
    for (int i = 0; i < indicesOfProduct.size(); i++) {
        t = indicesOfProduct[i];  // 对要生产的产物product的生产方式进行排序
        sort(record[t].method, record[t].method + record[t].cnt, cmp);
    }
    DFS(0, m);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%02d", ans[i][j]);
            if (j != ans[i].size() - 1) {
                printf(" + ");
            } else {
                printf(" -> ");
            }
        }
        printf("%02d\n", indicesOfProduct[i]);
    }
    return 0;
}