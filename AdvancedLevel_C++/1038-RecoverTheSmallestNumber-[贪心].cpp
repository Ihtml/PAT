#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool cmp(string a, string b) {
    return a + b < b + a; // 字符串数字从小到大排序
}
string str[10010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string s;
    for (int i = 0; i < n; i++) {
        s += str[i];
    }
    while (s.length() != 0 && s[0] == '0') {
        s.erase(s.begin());  // 删除字符串的第一个字符
    }
    if (s.length() == 0) {
        cout << 0;
    }
    cout << s;
    return 0;
}
