#include <iostream>
int a[1001];
using namespace std;
int main() {
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[temp]++;
    }
    for (int i = 0; i < 1001; i++) {
        if (a[i]) {
            a[i]--;
            if (i < m && a[m - i]) {
                cout << i << " " << m - i;
                return 0;
            }
            a[i]++;
        }
    }
    cout << "No Solution";
    return 0;
}