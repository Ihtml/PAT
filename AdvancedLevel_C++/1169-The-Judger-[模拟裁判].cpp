#include <iostream>
#include <vector>
using namespace std;
int n, m, ta, tb;
vector<int> win, v, fail(11), st(100001);  // 用set会超时，用数组空间换时间
bool judge(int t) {
    if (st[t]) {  // 这个数字已经出现过
        return false;
    }  //  要求是给出的数字必须是前面已经出现的某两个正整数之差，
    for (int i = 0; i < v.size(); i++) {
        int a = t + v[i];
        if (a < 100001 && st[a])
            return true;
    }
    // 转换为现在这个人出的数字，加上已经出过的某个数，看是不是等于另一个已经出过的数字。
    return false;
}
int main() {
    scanf("%d %d", &ta, &tb);
    st[ta] = st[tb] = 1;
    v.push_back(ta);  // v收集已经出现过的数字
    v.push_back(tb);
    scanf("%d %d", &n, &m);
    int A[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (fail[i]) {
                continue;
            }
            if (judge(A[i][j]) == false) {
                fail[i] = 1;
                printf("Round #%d: %d is out.\n", j, i);
            } else {
                st[A[i][j]] = 1;
                v.push_back(A[i][j]);
                if (j == m) {
                    win.push_back(i);
                }
            }
        }
    }
    if (win.size() == 0) {
        printf("No winner.");
    } else {
        printf("Winner(s):");
        for (auto it : win) {
            printf(" %d", it);
        }
    }
    return 0;
}