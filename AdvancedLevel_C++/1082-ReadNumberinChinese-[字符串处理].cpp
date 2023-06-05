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
    return 0;
}