#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
int main() {
    cin >> n >> m;
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int minans = sum[n];
}