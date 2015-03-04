#include <stdio.h>

const int LIM = 20;
int gcd(int a, int b){
	return b ? gcd (b, a % b) : a;
}

int main(){
  long long ans = 2;
  for (int i = 3; i <= LIM; ++i){
    int g = gcd(ans, i);
    if (g != i)
      ans *= i / g;
  }
  printf("%lld\n", ans);
  return 0;
}
