#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, t, minH = 1000, maxT = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        minH = min(minH, t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        maxT = max(maxT, t);
    }
    if (minH > maxT) {
        cout << "Yes " << minH - maxT;
    } else {
        cout << "No " << maxT - minH + 1;
    }

    return 0;
}