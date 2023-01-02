#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    string s1, s2;
    int n;
    cin >> s1 >> n;
    s2 = s1.substr(s1.length()-n) + s1.substr(0, s1.length()-n);
    double ans = stod(s2) / stod(s1);
    printf("%.2f", ans);
    // cout <<fixed<< setprecision(2) << ans;
    // cout << setprecision(6);
    return 0;
}