#include <stdio.h>

const int SUM = 1000;

bool is_pyth(int a, int b, int c){
  return a * a + b * b == c * c;
}

int main(){
  for (int a = 1; a < SUM; ++a){
    for (int b = a; b < SUM; ++b){
      int c = SUM - a - b;
      if (is_pyth(a, b, c))
        printf("%d\n", a * b * c);
    }
  }
  return 0;
}
