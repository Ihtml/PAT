#include <iostream>
using namespace std;
int main() {
    int n, m, temp, d, D;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        d = 0;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            d = max(d, temp);
        }
        cout << d << ((i == n - 1) ? '\n' : ' ');
        D = max(D, d);
    }
    cout << D;
    return 0;
}
int main1() {
    int n, m, temp, win = -1, Win = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        win = -1;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp > win) {
                win = temp;
            }
        }
        if (i == 0) {
            cout << win;
        } else {
            cout << " " << win;
        }
        if (win > Win) {
            Win = win;
        }
    }
    cout << endl << Win;
    return 0;
}