#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>

std::string allowed("();:,.'?-!");
bool isOk(char c){
  return (allowed.find(c) != std::string::npos || 
      isspace(c) || isalpha(c) || isdigit(c));
}

std::string guess_password(int codes[], int n, int& ans){
  std::string res;
  int len = 3;
  for (int i = 0; i < len; ++i){
  	for (char c = 'a'; c <= 'z'; ++c){
      int iter = 0;
  		bool is_ok = true;
  		for (int j = i; is_ok && j < n; j += len){
  			is_ok = isOk((char) (c ^ codes[j]));
        iter += c ^ codes[j];
      }
  		if (is_ok){
  			res += c;
        ans += iter;
  			break;
  		} else {
        iter = 0;
      }
  	}
  }
  return res;
}

int main(){
  FILE *f = fopen("059.txt", "r");
  int n = 0;
  int codes[1000000];
  int val;
  int is_read = fscanf(f, "%d,", &val);
  while (is_read && !feof(f)){
    codes[n++] = val;
    is_read = fscanf(f, "%d,", &val);
  }
  int wtf = 0;
  std::string ans = guess_password(codes, n, wtf);
  printf("%d\n", wtf);
  fclose(f);
  return 0;
}
