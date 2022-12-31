#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n < 5) {
        if (n == 2 || n == 3) {
            return true;
        }
        return false;
    }
    if (n % 6 != 1 && n % 6 != 5) {  // 素数一定在6倍数的两侧
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {  // 判断是否是5或7的倍数
            return false;
        }
    }
    return true;
}
int main() {
    int num, flag = 0;
    cin >> num;
    if (isPrime(num)) {
        if (isPrime(num - 6)) {
            flag = 1;
            num = num - 6;
        } else if (isPrime(num + 6)) {
            flag = 1;
            num = num + 6;
        }
    }
    if (!flag) {
        for (int i = num+1;; i++) {
            if (isPrime(i)) {
                if (isPrime(i - 6) || isPrime(i + 6)) {
                    num = i;
                    break;
                }
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    cout << num;
    return 0;
}