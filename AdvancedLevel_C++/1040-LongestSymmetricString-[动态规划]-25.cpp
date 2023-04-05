/*
Q:输出字符串里最长回文串的长度
A:dp[i][j]表示s[i]到s[j]所表示的字串是否是回⽂文字串。只有0和1
⾸先初始化dp[i][i] = 1, dp[i][i+1]，把⻓度为1和2的都初始化好，然后从L =
3开始一直到 L <= len 根据动态规划的递归⽅程来判断
*/
#include <iostream>
using namespace std;
int dp[1010][1010];
int main(){
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    // TODO DP
    return 0;
}