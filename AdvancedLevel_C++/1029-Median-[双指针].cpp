#include <limits.h>
#include <iostream>
using namespace std;
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int k[maxn];
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a1[i]);
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &a2[i]);
    }
    int target = (n + m + 1) / 2;
    i = 1, j = 1;
    while (i <= n && j <= m) {
        ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
        if (++cnt == target)
            break;
    }
    if (i <= n && cnt < target) {
        ans = a1[i + target - cnt - 1];
    } else if (j <= m && cnt < target) {
        ans = a2[j + target - cnt - 1];
    }
    printf("%d", ans);
    return 0;
}
int main1() {
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    k[n + 1] =
        INT_MAX;  // 如果不设k[n+1]为最大值，则k[n+1]及以后都为0，比较时会出错
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; i <= n && j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] <= temp) {
            count++;
            if (count == midpos) {
                cout << k[i];
                return 0;
            }
            i++;
        }
        count++;
        if (count == midpos) {
            cout << temp;
            return 0;
        }
    }
    while (count < midpos) {
        count++;
        if (count == midpos) {
            cout << k[i];
            return 0;
        }
        i++;
    }
}