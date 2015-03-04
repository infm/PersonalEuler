#include <stdio.h>
#include <algorithm>
#include <limits.h>

const int n = 15;

int calc(int tr[][n]){
  int d[n][n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        d[i][j] = 0;
  d[0][0] = tr[0][0];
  for (int i = 1; i < n; ++i)
    d[i][0] = d[i - 1][0] + tr[i][0];
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < i + 1; ++j)
      d[i][j] = std::max(d[i - 1][j - 1], d[i - 1][j]) + tr[i][j];
  int solution = INT_MIN;
  for (int j = 0; j < n; ++j)
    solution = std::max(solution, d[n - 1][j]);
  return solution;
}

int main(){
  FILE *f = fopen("018.txt", "r");
  int tr[n][n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j)
      fscanf(f, " %d", &tr[i][j]);
  printf("%d\n", calc(tr));
  fclose(f);
  return 0;
}
