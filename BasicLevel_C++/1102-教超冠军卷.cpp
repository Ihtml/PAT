#include <iostream>
using namespace std;
int main() {
    int n, sale, num, maxSale = -1, maxNum = -1;
    string id, maxSaleId, maxNumId;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> sale >> num;
        if (num > maxNum) {
            maxNum = num;
            maxNumId = id;
        }
        if (sale * num > maxSale) {
            maxSale = sale * num;
            maxSaleId = id;
        }
    }
    cout << maxNumId << " " << maxNum << endl;
    cout << maxSaleId << " " << maxSale << endl;
    return 0;
}