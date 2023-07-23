/*
给三个正整数N、K、P，将N表示成K个正整数（可以相同，递减排列）的P次方和，
如果有多种方案，选择底数n1 +…+nk最大的方案，
如果还有多种方案，选择底数序列的字典序最大的方案
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, k, p, maxSum = -1;
vector<int> v, ans, tempAns;
int main() {
    scanf("%d%d%d", &n, &k, &p);
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
    return 0;
}