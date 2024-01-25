#include <iostream>
using namespace std;
string S, P;
int main() {  // 找出包含P里的字母和次序的最小子串
    cin >> S >> P;
    int n = S.length(), m = P.length();
    string ans = S;
    int l = n;
    for (int i = 0; i <= n - m; i++) {
        if (S[i] == P[0]) {
            string sub = "";
            int j = i, k = 0;  // 双指针判断子序列
            while (k < m) {
                if (S[j] == P[k]) {
                    k++;
                }
                sub += S[j];
                j++;
                if (sub.size() > l) {  // 防止死循环
                    break;
                }
            }
            if (sub.size() < l) {
                ans = sub;
                l = ans.size();
            }
        }
    }
    cout << ans;
    return 0;
}