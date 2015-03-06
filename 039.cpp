#include <stdio.h>

const int LIM = 1000;

bool is_pyth(int a, int b, int c){
  return a * a + b * b == c * c;
}

int main(){
  int ans = 0;
  int max_sum = 0;
  for (int sum = 3; sum <= LIM; ++sum){
    int sols = 0;
    for (int a = 1; a < sum; ++a){
      for (int b = a; b < sum; ++b){
        int c = sum - a - b;
        if (is_pyth(a, b, c))
          sols++;
      }
    }
    if (sols > ans){
      ans = sols;
      max_sum = sum;
    }
  }
  printf("%d\n", max_sum);
  return 0;
}
