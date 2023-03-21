#include <limits.h>
#include <iostream>
using namespace std;
int k[200005];
int main() {
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    k[n + 1] = INT_MAX;  // 如果不设k[n+1]为最大值，则k[n+1]及以后都为0，比较时会出错
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; i<=n && j <= m; j++) {
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