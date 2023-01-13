#include <iostream>
using namespace std;
int main() {
    int n, sum, A[4] = {2, 0, 1, 9};
    cin >> n;
    for (int i = 0; i < min(4, n); i++)
        cout << A[i];
    for (int i = 4; i < n; i++) {
        sum = (A[0] + A[1] + A[2] + A[3]) % 10;
        cout << sum;
        A[0] = A[1];
        A[1] = A[2];
        A[2] = A[3];
        A[3] = sum;
    }
    return 0;
}

#include <vector>
int main1() {
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