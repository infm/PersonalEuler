#include <stdio.h>
#include <vector>

bool is_pali(int num){
  std::vector<int> v;
  while (num > 0){
    v.push_back(num % 10);
    num /= 10;
  }
  bool pali = true;
  for (size_t i = 0, j = v.size() - 1; pali && i < j; ++i, --j){
    pali = v[i] == v[j];
  }
  return pali;
}

int main(){
  int res = 0;
  for (int i = 100; i < 1000; ++i){
    for (int j = i; j < 1000; ++j){
      int num = i * j;
      if (is_pali(num) && num > res)
        res = num;
    }
  }
  printf("%d\n", res);
  return 0;
}
