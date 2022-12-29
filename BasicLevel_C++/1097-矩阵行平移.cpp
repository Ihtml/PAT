#include <iostream>
using namespace std;
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    int A[100][100], sum[100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (i % 2 != 0) {  
                sum[j] += A[i][j];
            }
        }
    }
    int ctn = 1;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < ctn; j++) {
            sum[j] += x;
        }
        for (int j = ctn ; j < n; j++) {
            sum[j] += A[i][j-ctn];
        }
        ctn = ctn  % k + 1;
    }
    int i = 0;
    cout << sum[i];
    for (i = 1; i < n; i++) {
        cout << " " << sum[i];
    }
    return 0;
}