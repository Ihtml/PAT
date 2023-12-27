#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int a) {
    if (a < 5) {
        if (a == 2 || a == 3) {
            return true;
        }
        return false;
    }
  if (a % 6 != 1 && a % 6 != 5) {
    return false;
  }
  for (int i = 5; i * i <= a; i += 6) {
    if (a % i == 0 || a % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  long int n;
  scanf("%ld", &n);
  vector<int> book;
  for (int i = 2; i < 5000; i++) {
    if (isPrime(i)) {
      book.push_back(i);
    }
  }
  printf("%ld=", n);
  if (n == 1 || n == 2 || n == 3) {
    printf("%ld", n);
    return 0;
  }
  int first = 1;
  for (int i = 0; i < book.size(); i++) {
    int p = 0, k = 0;
    while (n % book[i] == 0) {
      p = book[i];
      k++;
      n = n / book[i];
    }
    if (p > 0) {
      if (!first) {
        printf("*");
      } else {
        first = 0;
      }
      printf("%d", p);
    }
    if (k > 1) {
      printf("^%d", k);
    }
  }
  return 0;
}