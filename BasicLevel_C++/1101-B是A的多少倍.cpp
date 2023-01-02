#include <iostream>
using namespace std;
int main(){
    string s1, s2;
    int n;
    double d1, d2;
    cin >> s1 >> n;
    s2 = s1.substr(s1.length()-n) + s1.substr(0, s1.length()-n);
    d1 = stoi(s1);
    d2 = stoi(s2);
    printf("%.2f", d2/d1);
    return 0;
}