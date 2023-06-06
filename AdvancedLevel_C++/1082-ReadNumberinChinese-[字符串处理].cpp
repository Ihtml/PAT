/*给定一个不超过9位的整数，你应该用传统的中文方式阅读它~
 * 如果是负的，首先输出“Fu”。 例如，-123456789被读作“Fu yi Yi er Qian san Bai si
 * Shi wu Wan liu Qian qi Bai ba Shi jiu”。
 * 注意：零（“ling”）必须根据中国传统正确处理。 例如，100800是“yi Shi Wan ling
 * ba Bai”
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = {"ling", "yi",  "er", "san", "si",
                  "wu",   "liu", "qi", "ba",  "jiu"};
string c[6] = {"Ge", "Shi", "Bai", "Qian", "Yi", "Wan"};
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu";
        n = -n;
    }
    int part[3];
    part[0] = n / 100000000;
    part[1] = (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false;  // 是否在非零数字前输出合适的ling
    int printCnt = 0;  // 用于维护单词前没有空格，之后输入的单词都在前面加一个空格。
    for (int i = 0; i < 3; i++) {
        int temp = part[i];  // 三个部分，每部分内部的命名规则都一样，都是X千X百X十X
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j;  // 当前数字的位置
            if (curPos >= 9) {
                continue;  // 最多九位数
            }
            int cur = (temp / J[j]) % 10;  // 取出当前数字
            if (cur != 0) {
            }
        }
    }

    return 0;
}