#include <bits/stdc++.h>
using namespace std;

int main() { 
  set<int> a;

  a.insert(10);
  a.insert(20);
  a.insert(30);
  a.insert(10);

  for(set<int>::iterator i = a.begin(); i != a.end(); i++) {
    printf("%d\n",*i);
  }
  printf("\n");

  // 在set中大于某个数的第一个数
  set<int>::iterator x = a.upper_bound(15);
  if(x == a.end()) {
    printf("没有比这个更大的\n");
  } else {
    printf("%d\n",*x);
  }
  printf("\n");

  // 在set中查找最大的小于某个数的数
  x = a.upper_bound(15);
  if(x == a.begin()) {
    printf("没有比这个更小的\n");
  } else {
    x--;
    if(x == a.end()) {
      printf("NO\n");
    } else {
      printf("%d\n",*x);
    }
    printf("\n");
  }

  return 0;
}