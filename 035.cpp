#include <stdio.h>

const int LIM = 1000000;

void erath_sieve(bool* prime, int N){
  prime[0] = false;
  for (int i = 1; i < N; ++i)
    prime[i] = true;

  for (int i = 2; i <= LIM; ++i){
    if (!prime[i - 1])
      continue;
    for (int j = 2; i * j <= N; ++j)
      prime[i * j - 1] = false;
  }
}

bool chckrt(int num, bool prime[], int dignum){
  int new_num = num;
  bool ok = prime[num - 1];
  for (int i = 0; ok && i < dignum; ++i){
    int properdig = new_num % 10;
    for (int j = 1; j < dignum; ++j)
      properdig *= 10;
    new_num = new_num / 10 + properdig;
    ok = prime[new_num - 1];
  }
  return ok;
}

int main(){
  const int n = LIM + 7;
  bool prime[n];
  erath_sieve(prime, n);

  int count = 0;
  int dignum = 1;
  for (int i = 0, dl = 10; i < LIM; ++i){
    if (i >= dl){
      ++dignum;
      dl *= 10;
    }
    if (prime[i] && chckrt(i + 1, prime, dignum))
      ++count;
  }
  printf("%d\n", count);
  return 0;
}
