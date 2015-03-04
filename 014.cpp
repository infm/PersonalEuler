#include <stdio.h>

typedef long long int ll;

const ll LIM = 1000000;

ll next(ll n){
  if (n % 2)
    return 3 * n + 1;
  return n / 2;
}

int main(){
  int max_len = 0;
  ll max_num = 0;
  for (ll i = 1; i < LIM; ++i){
    ll curr = i;
    int len = 0;
    while (curr > 1){
      curr = next(curr);
      len++;
    }
    if (len > max_len){
      max_len = len;
      max_num = i;
    }
  }
  printf("%d %lld\n", max_len, max_num);
  return 0;
}
