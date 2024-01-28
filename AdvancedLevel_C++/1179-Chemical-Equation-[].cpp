#include <iostream>
#include <vector>
using namespace std;
int n, k, m, t;
vector<int> rect, prod, equa;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        rect.push_back(t);
    }
    cin >> m;
    for (int i = 0; i < k; i++) {
        cin >> t;
        prod.push_back(t);
    }
    cin >> m;
    
    return 0;
}