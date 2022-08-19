#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000010];
struct node {
  int num;
  int to;
} b[2000010];
int tot;

string f(int num) {
  int i = a[num%2000000];
  if(i == 0) {
    tot++;
    a[num%2000000] = tot;
    b[tot].num = num;
    b[tot].to = 0;
    return "accepted";
  }
  while(1) {
    if(b[i].num == num) {
      return "ignored";
    }
    if(b[i].to == 0) {
      break;
    }
    i = b[i].to;
  }
  tot++;
  b[i].to = tot;
  b[tot].num = num;
  b[tot].to = 0;
  return "accepted";
}

int main() {
  scanf("%d",&n);
  int num;
  for(int i = 1; i <= n; i++) {
    scanf("%d",&num);
    printf("%s\n",f(num).c_str());
  }
  return 0;
}