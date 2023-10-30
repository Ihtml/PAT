/*分析：1.用数组arr标记两个人是否是朋友（邻接矩阵表示），用v标记所有人的同性朋友（邻接表表示）
2.对于一对想要在一起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两人是朋友的时候则可以输出C和D*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, bool> arr;
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    vector<int> v[10000];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] =
            arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    return 0;
}
