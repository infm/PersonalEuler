#include <stdio.h>

const int LIM = 100;

int main(){
  long long int sqsum = 0;
  for (int i = 1; i <= LIM; ++i)
    sqsum += i * i;
  long long int sumsq = LIM * (LIM + 1) / 2;
  sumsq *= sumsq;
  printf("%lld %lld %lld\n", sqsum, sumsq, sumsq - sqsum);
  return 0;
}
