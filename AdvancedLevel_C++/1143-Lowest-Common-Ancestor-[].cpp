// 给出一棵二叉搜索树的前序遍历，问结点u和v的共同最低祖先是谁
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, bool> mp;
int main(){
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for (int j = 0; j < n; j++) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u))
                break;
        }
    }
    return 0;
}