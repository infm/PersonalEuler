#include <stdio.h>

const long long int NUM = 600851475143;

int main(){
  long long int max = 1;
  long long int curr = 2;
  long long int num = NUM;
  while (num > 1) {
    if (num % curr == 0){
      max = curr;
      num /= curr;
    }
    curr++;
  }
  printf("%lld\n", max);
  return 0;
}
