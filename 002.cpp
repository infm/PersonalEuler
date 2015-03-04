#include <stdio.h>

int calc(int limit){
  int fib[] = {1, 1, 2};
  int ans = 0;
  while (fib[2] <= limit){
    if (!(fib[2] % 2))
      ans += fib[2];
    fib[0] = fib[1];
    fib[1] = fib[2];
    fib[2] = fib[0] + fib[1];
  }
  return ans;
}

int main(){
  printf("%d\n", calc(4000000));
  return 0;
}
