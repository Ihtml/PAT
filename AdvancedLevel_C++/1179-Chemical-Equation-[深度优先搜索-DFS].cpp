#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k, m, t;
const int maxn = 100;
string s;
vector<int> rect, prod, equa;
struct Equation {
    vector<int> method[6];  // 每种产物最多5个方程，还有一种是自己生产自己
    int ctn;  // 生产方式的数目
    Equation() { ctn = 0; }
} record[maxn];
bool Reactant[maxn] = {false};  // 如果原材料i存在，Reactant[i] = true;
bool Used[maxn] = {false};  // 如果原材料i被使用过，Used[i] = true;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        Reactant[t] = true;
    }
    cin >> m;
    for (int i = 0; i < k; i++) {
        cin >> t;
        prod.push_back(t);
    }
    cin >> k;
    getchar();
    for (int i = 0; i < k; i++) {
        getline(cin, s);
        vector<int> v;  // 获取s中的所有原料
    }
    return 0;
}