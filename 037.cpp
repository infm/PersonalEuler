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

bool suits(bool* prime, int num){
  int left = num % 10;
  int right = num / 10;
  bool cool = true;
  int p = 100;
  while (cool && left != num && right > 0){
    cool = prime[left - 1] && prime[right - 1];
    left = num % p;
    right = num / p;
    p *= 10;
  }
  return cool;
}

int main(){
  bool prime[LIM];
  erath_sieve(prime, LIM);

  long long int ans = 0;
  for (int i = 10; i < LIM; ++i){
    if (prime[i - 1] && suits(prime, i))
      ans += i;
  }
  printf("%lld\n", ans);
  return 0;
}
