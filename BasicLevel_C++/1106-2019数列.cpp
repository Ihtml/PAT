#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, p = 4;
    vector<int> A(4);
    A[0] = 2;
    A[1] = 0;
    A[2] = 1;
    A[3] = 9;
    cin >> n;
    for (int i = 0; i < min(4, n); i++)
        cout << A[i];
    while (n - 4 > 0) {
        A[p] = (A[p - 1] + A[p - 2] + A[p - 3] + A[p - 4]) % 10;
        cout << A[p];
        n--;
        p++;
    }
    return 0;
}