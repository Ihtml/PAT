#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt = 0, t;
int main() {
    cin >> n >> m;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t;
        pre[i] = pre[i - 1] + t;
    }
    for (int i = 1; i <= n; i++) {  // i表示间隔
        for (int j = i; j <= n; j++) {
            if ((pre[j] - pre[i - 1]) <= m) {  // 包括j块在内的前i块价格总和
                cnt++;
            } else {
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}