/*
Q:给出一个数字n，求1~n的所有数字⾥⾯面出现1的个数

*/
#include <iostream>
using namespace std;
int main() {
    // now为当前位的数字，left为now左边的所有数字构成的数字，right是now右边的所有数字构成的数字
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    cin >> n;
    while (n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if (now == 0) {
            ans += left * a;
        } else if (now == 1) {
            ans += left* a + right + 1;
        } else {
            ans += (left + 1) * a;
        }
        a = a * 10;
    }
    cout << ans;
    return 0;
}