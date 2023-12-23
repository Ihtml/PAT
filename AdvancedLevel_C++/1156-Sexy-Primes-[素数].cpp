#include <iostream>
using namespace std;
bool isPrime(int a) {
    if (a == 2 || a == 3) {
        return true;
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