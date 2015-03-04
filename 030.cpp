#include <stdio.h>

typedef long long int ll;

const int LIM = 10000000;

ll fifth(ll n){
  return n * n * n * n * n;
}

int main(){
  ll ans = 0;
  for (int i = 10; i <= LIM; ++i){
    ll fsum = 0;
    int num = i;
    while (num > 0){
      fsum += fifth(num % 10);
      num /= 10;
    }
    if (fsum == i)
      ans += i;
  }

  printf("%lld\n", ans);
  return 0;
}

