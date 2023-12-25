// 性感素数是指形如(p, p +6)这样的一对素数。
// 给定一个整数，判断其是否为一个性感素数。
// 若N是一个性感素数，则在一行中输出Yes，并在第二行输出与N配对的另一个性感素数（若这样的数不唯一，输出较小的那个）。
// 若N不是性感素数，则在一行中输出No，然后在第二行输出大于N的最小性感素数。
#include <iostream>
using namespace std;
bool isPrime(int a) {
    if (a < 5) {
        if (a == 2 || a == 3) {
            return true;
        } else {
            return false;
        }
    }
    if (a % 6 != 1 && a % 6 != 5) {
        return false;
    }
    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int p, ans;
int main() {
    cin >> p;
    if (isPrime(p) && isPrime(p - 6)) {
        cout << "Yes\n" << p - 6;
    } else if (isPrime(p) && isPrime(p + 6)) {
        cout << "Yes\n" << p + 6;
    } else {
        for (ans = p + 1;; ans++) {
            if (isPrime(ans) && isPrime(ans - 6)) {
                break;
            }
            if (isPrime(ans) && isPrime(ans + 6)) {
                break;
            }
        }
        cout << "No\n" << ans;
    }
    return 0;
}