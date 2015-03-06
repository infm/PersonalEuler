#include <stdio.h>
#include <vector>

const int LIM = 1000000;

typedef unsigned int ui;

bool is_palindrome_dec(ui n){
  std::vector<int> digs;
  while (n > 0){
    digs.push_back(n % 10);
    n /= 10;
  }
  for (size_t i = 0, j = digs.size() - 1; i < j; ++i, --j)
    if (digs[i] != digs[j])
      return false;
  return true;
}

bool is_palindrome_bin(ui n){
  int j = 0;
  for (int i = 0; i < 8 * sizeof(n); ++i)
    if (n & (1 << i))
      j = i;
  for (int i = 0; i <= j; ++i, --j)
    if (!(n & (1 << i)) != !(n & (1 << j)))
      return false;
  return true;
}

int main(){
  long long int sum = 0;
  for (ui i = 1; i < LIM; ++i)
    if (is_palindrome_bin(i) && is_palindrome_dec(i))
      sum += i;
  printf("%lld\n", sum);
  return 0;
}
