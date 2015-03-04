#include <stdio.h>

const int N = 21;

int main(){
  long long int d[N + 1][N + 1];
  for (int i = 0; i < N + 1; ++i)
    for (int j = 0; j < N + 1; ++j)
      d[i][j] = 0;
  d[1][1] = 1;
  for (int i = 1; i < N + 1; ++i){
    for (int j = 1; j < N + 1; ++j){
      if (i == j && i == 1)
        continue;
      d[i][j] = d[i - 1][j] + d[i][j - 1];
    }
  }
  printf("%lld\n", d[N][N]);
  return 0;
}
