#include <iostream>
#include <vector>
using namespace std;
int n, ans = 0;
int main() {
    cin >> n;
    vector<int> A(n), L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // L[i]表示第i个数的右边有几个连续下降的数
    // 过程中可以有相等的数字，但是只记录不重复的数字的数量
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && A[j] >= A[j + 1]) {
            if (A[j] > A[j + 1]) {
                L[i]++;
            }
            j++;
        }
    }
    // R[i]则表示第i个数左边有几个连续下降的数
    for (int i = n - 1; i > 0; i--) {
        int j = i;
        while (j - 1 >= 0 && A[j] >= A[j - 1]) {
            if (A[j] > A[j - 1]) {
                R[i]++;
            }
            j--;
        }
    }
    // 取L[i]和R[i]中较大的那个数*100+200
    for (int i = 0; i < n; i++) {
        ans += max(L[i], R[i]) * 100 + 200;
    }
    cout << ans;
    return 0;
}