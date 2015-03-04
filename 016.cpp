#include <stdio.h>
#include <vector>

const int LIM = 1000;

int main(){
  std::vector<int> digs;
  digs.push_back(1);
  for (int i = 1; i <= LIM; ++i){
    bool carry = false;
    for (size_t j = 0; j < digs.size(); ++j){
      int mul = digs[j] * 2;
      digs[j] = mul % 10;
      if (carry)
        digs[j]++;
      carry = mul / 10;
    }
    if (carry)
      digs.push_back(1);
  }
  int ans = 0;
  for (size_t i = 0; i < digs.size(); ++i)
    ans += digs[i];
  printf("%d\n", ans);
  return 0;
}
