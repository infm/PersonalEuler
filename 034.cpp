#include <stdio.h>

typedef long long int ll;

const int LIM = 10000000;

ll fact(ll n){
  if (n == 0)
    return 1;
  if (n < 3)
    return n;
  return n * fact(n - 1);
}

int main(){
  ll ans = 0;
  for (int i = 10; i <= LIM; ++i){
    ll fsum = 0;
    int num = i;
    while (num > 0){
      fsum += fact(num % 10);
      num /= 10;
    }
    if (fsum == i)
      ans += i;
  }

  printf("%lld\n", ans);
  return 0;
}
