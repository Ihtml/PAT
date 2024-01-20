#include <iostream>
using namespace std;
string s;
bool allPrime = true;
bool isPrime(int n) {
    if (n < 6) {
        if (n == 2 || n == 3) {
            return true;
        }
        return allPrime = false;
    }
    if (n % 6 != 1 && n % 6 != 5) {
        return allPrime = false;
    }
    for (int i = 5; i * i < n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return allPrime = false;
        }
    }
    return true;
}
int main() {
    cin >> s;
    while (s.length()) {
        cout << s << " " << (isPrime(stoi(s)) ? "Yes\n" : "No\n");
        s = s.substr(1);
    }
    if (allPrime) {
        cout << "All Prime!";
    }
    return 0;
}