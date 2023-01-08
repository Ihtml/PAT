#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
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
struct node {
    int n, num;
    friend bool operator<(node& a, node& b) {
        if (a.n != b.n)
            return a.n < b.n;
        return a.num < b.num;
    }
} T;
vector<node> A;

int main() {
    int n, k, m, temp, sum, sum2, X, Y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        A.clear();
        cout << "Case " << i << "\n";
        cin >> k >> m;
        if (k * 9 < m) {
            cout << "No Solution\n";
        } else {
            temp = pow(10, k - 2);
            for (int i = temp / 10; i < temp; i++) {
                sum = 18, sum2 = 0;
                X = i, Y = i + 1;
                while (X) {
                    sum += X % 10;
                    X /= 10;
                    if (sum > m)
                        break;
                }
                while (Y) {
                    sum2 += Y % 10;
                    Y /= 10;
                }
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