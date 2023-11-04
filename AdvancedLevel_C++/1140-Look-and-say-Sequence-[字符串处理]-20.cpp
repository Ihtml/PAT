/*
给两个数字D和n，第一个序列是D，后一个序列描述前一个序列的所有数字以及这个数字出现的次数，
比如D出现了1次，那么第二个序列就是D1，对于第二个序列D1，第三个序列这样描述：D出现1次，1出现1次，所以是D111……
以此类推，输出第n个序列
*/
#include <iostream>
    using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;  // 从输入中获取初始字符串 s 和重复次数 n

    for (int i = 1; i < n; i++) {  // 重复处理字符串 n 次
        string st;
        int ctn = 1;
        s = s + "#";  // 添加一个特殊字符 # 以确保最后一个字符也被处理

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {  // 如果当前字符与下一个字符相同
                ctn++;               // 增加计数
            } else {
                st += s[i] +
                      to_string(ctn);  // 否则将当前字符与计数附加到新字符串 st
                ctn = 1;  // 重置计数
            }
        }

        s = st;  // 更新字符串 s 为新生成的字符串 st
    }

    cout << s;  // 输出最终结果
    return 0;
}