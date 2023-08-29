/*Q：一幅画里面的鸟为同一棵树上的，问有多少棵树和多少只鸟，以及对于两只鸟判断是否在同一个树上*/
#include <iostream>
using namespace std;
int n, m, k;
const int maxn = 10010;
int fa[maxn] = {0}, cnt[maxn] = {0};
bool exist[maxn];
int main() {
    cin >> n;
    for (int i = 0; i <= maxn; i++) {
        fa[i] = i;
    }
    int id, temp;
    for (int i = 0; i < n; i++) {
        cin >> k >> id;
        exist[id] = true;
    }

    return 0;
}