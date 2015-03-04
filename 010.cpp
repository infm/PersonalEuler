#include <stdio.h>

const int LIM = 2000000;

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

int main(){
  const int n = LIM + 7;
  bool prime[n];
  erath_sieve(prime, n);
  long long int ans = 0;
  for (int i = 0; i < LIM; ++i){
    if (prime[i])
      ans += i + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
