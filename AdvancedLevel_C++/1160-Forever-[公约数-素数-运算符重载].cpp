// “天长地久数”是指一个K位正整数A，
// 其满足条件为A的各位数字之和为m，A+1的各位数字之和为n，
// 且m与n的最大公约数是一个大于2的素数。
// 所有天长地久数最后两位为”99″
// 将末尾的两个’9’隐藏后可直接带入暴力循环判断。将所有可能答案存储后排序输出
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct node {
    int n, num;
    // friend bool operator<(node& a, node& b) {
    //     if (a.n != b.n) {
    //         return a.n < b.n;
    //     }
    //     return a.num < b.num;
    // }
    // 将 < 运算符的重载改为全局函数
    friend bool operator<(const node& a, const node& b) {
        if (a.n != b.n) {
            return a.n < b.n;
        }
        return a.num < b.num;
    }
} T;
bool isPrime(int n) {
    if (n < 5) {
        if (n == 3) {  // 本题要求是大于2的素数
            return true;
        }
        return false;
    }
    if (n % 6 != 5 && n % 6 != 1) {
        return false;
    }
    for (int i = 5; i * i < n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
// 系统不支持__gcd时，自己实现
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int N, K, m, temp, sum, sum2, X, Y;
vector<node> A;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K >> m;
        cout << "Case " << i << '\n';
        A.clear();
        if (K * 9 < m)
            cout << "No Solution\n";
        else {
            temp = pow(10, K - 2);
            for (int i = temp / 10; i < temp; i++) {
                sum = 18, sum2 = 0, X = i, Y = i + 1;
                while (X) {
                    sum += X % 10;
                    X /= 10;
                    if (sum > m) {
                        break;
                    }
                }
                while (Y) {
                    sum2 += Y % 10;
                    Y /= 10;
                }
                // 如果系统支持，可以使用__gcd(m, sum2)
                if (sum == m && isPrime(gcd(m, sum2))) {
                    T.n = sum2, T.num = i;
                    A.push_back(T);
                }
            }
            sort(A.begin(), A.end());
            if (A.empty()) {
                cout << "No Solution\n";
            }
            for (auto& it : A) {
                cout << it.n << " " << it.num << "99\n";
            }
        }
    }
    return 0;
}