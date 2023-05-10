/*
Q:给出一个n个数的序列，数字为0~n-1的乱序，每次用两两交换的方式而且只能用0和另一个数交换，使序列变成有序的，
问最少需要多少步骤。
*/
#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, book[100001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        book[t] = i;  // 表示t数字当前正在占着哪一个位置。
    }
    for (int i = 1; i < n; i++) {
        if (book[i] != i) {
            while (book[0] != 0) {  // book[0]是哨兵
                swap(book[0], book[book[0]]);
                cnt++;
            }
            if (book[i] != i) {
                swap(book[0], book[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}