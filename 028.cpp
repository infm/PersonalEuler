#include <stdio.h>

const int N = 1001;

int main(){
  long long int sum = 1;
  for (int side = 3; side <= N; side += 2){
    int min = (side - 2) * (side - 2) + side - 1;
    sum += min + (min + side - 1) + 
      (min + 2 * (side - 1)) + (min + 3 * (side - 1));
  }
  printf("%lld\n", sum);
  return 0;
}
