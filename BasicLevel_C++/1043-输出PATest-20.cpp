#include <iostream>
using namespace std;
int main() {
  int c, arr[128] = {0};
  while ((c = cin.get()) != EOF) {
    arr[c]++;
  }
  while (arr['P'] > 0 || arr['A'] > 0 || arr['T'] > 0 || arr['e'] > 0 ||
         arr['s'] > 0 || arr['t'] > 0) {
    if (arr['P']-- > 0)
      cout << 'P';
    if (arr['A']-- > 0)
      cout << 'A';
    if (arr['T']-- > 0)
      cout << 'T';
    if (arr['e']-- > 0)
      cout << 'e';
    if (arr['s']-- > 0)
      cout << 's';
    if (arr['t']-- > 0)
      cout << 't';
  }
  return 0;
}