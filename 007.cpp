#include <stdio.h>

const int N = 1000000;
const int LIM = 10001;

int main(){
  bool prime[N];
  prime[0] = false;
  for (int i = 1; i < N; ++i)
    prime[i] = true;

  for (int i = 2; i <= LIM; ++i){
    if (!prime[i - 1])
      continue;
    for (int j = 2; i * j <= N; ++j)
      prime[i * j - 1] = false;
  }

  int c = 0;
  for (int i = 1; i < N && c < LIM; ++i){
    if (prime[i - 1])
      ++c;
    if (c == LIM)
      printf("%d\n", i);
  }
  return 0;
}
