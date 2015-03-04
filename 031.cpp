#include <stdio.h>

int count_change(int money, int* coins, int n) {
//  printf("%d %d %d\n", money, *coins, n);
  if (money == 0)
    return 1;
  if (n < 1 || money < 0)
    return 0;
  return count_change(money - *coins, coins, n) + 
    count_change(money, coins + 1, n - 1);
}

int main(){
  int money = 200;
  int coins[] = {1, 2, 5, 10, 20,
    50, 100, 200};
  printf("%d\n", count_change(money, coins, 8));
  return 0;
}
