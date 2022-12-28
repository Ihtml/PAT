#include <iostream>
using namespace std;
int main() {
    int K, N, flag;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> N;
        flag = 0;
        int len = N / 2 +1;
        for (int a = 1; a < len; a++) {
            if (flag)  break;
            if ( N % a != 0) {
                continue;
            }
            for (int b = a + 1; b < N; b++) {
                if (flag) break;
                if ( N % b != 0) {
                    continue;
                }
                for (int c = b + 1; c < N; c++) {
                    if (flag) break;
                    if (N % c != 0) {
                        continue;
                    }
                    for (int d = c + 1; d <= N; d++) {
                        if (N % d != 0) {
                            continue;
                        }
                        if ( (a + b + c + d) % N == 0) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}