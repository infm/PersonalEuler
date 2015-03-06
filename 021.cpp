#include <stdio.h>

const int LIM = 9999;

int d(int n){
  int res = 1;
  for (int i = 2; i < n; ++i){
    if (!(n % i))
      res += i;
  }
  return res;
}

int main(){
  int arr[LIM] = {0};
  for (int i = 0; i < LIM; ++i)
    arr[i] = d(i + 1);

  long long int sum = 0;
  for (int i = 0; i < LIM; ++i){
    int val = arr[i];
    if (val <= LIM && val > 0 && 
        i + 1 != val &&
        arr[val - 1] == i + 1){
      sum += val;
    }
  }
  printf("%lld\n", sum);
  return 0;
}
