#include <iostream>
using namespace std;
int n, a = 0, b = 1, c = 1, dis = 1e9, last;
int main() {
    cin >> n;
    while (abs(n - c) < dis) {  // 越接近那个数时，距离越小
        dis = abs(n - c);
        a = b;
        b = c;
        last = c;
        c = a + b;
    }
    cout << last;
    return 0;
}