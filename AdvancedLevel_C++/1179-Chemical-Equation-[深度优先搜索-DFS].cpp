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
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        Reactant[t] = true;
    }
    cin >> m;
    for (int i = 0; i < k; i++) {
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
    return 0;
}