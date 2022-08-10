#include <bits/stdc++.h>
using namespace std;

int a[50];

void init() {
  int x = 1;
  for(int i = 0; i <= 20; i++) {
    a[i] = x;
    x *= 2;
  }
}

int find(int x) {
  for(int i = 0; i < 20; i++) {
    if(a[i]<=x&&x<a[i+1]) {
      return i;
    }
  }
}

string f(int x) {
  if(x == 1) {
    return "2(0)";
  }
  if(x == 2) {
    return "2";
  }
  if(x == 3) {
    return "2+2(0)";
  }
  int y = find(x);
  if(x-a[y] == 0) {
    return "2("+f(y)+")";
  } else {
    return "2("+f(y)+")+"+f(x-a[y]);
  }
}

int main() {
  init();
  int n;
  cin>>n;
  cout<<f(n)<<"\n";
  return 0;
}