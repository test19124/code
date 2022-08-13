#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
  int s,t;
} a[100010];

bool cmp(node x,node y) {
  if(x.t == y.t) {
    return x.s > y.s;
  }
  return x.t < y.t;
}

int main() {
  scanf("%d",&n);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d",&a[i].s,&a[i].t);
  }
  sort(a+1,a+n+1,cmp);
  int s = a[1].t,x = 1;
  for(int i = 2; i <= n; i++) {
    if(a[i].s > s) {
      s = a[i].t;
      x++;
    }
  }
  printf("%d\n",x);
  return 0;
}