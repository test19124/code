#include <bits/stdc++.h>
using namespace std;

int n,m;
struct node {
  int s,t;
} a[100010];

bool cmp(node x,node y) {
  if(x.s == y.s) {
    return x.t > y.t;
  }
  return x.s < y.s;
}

int main() {
  scanf("%d%d",&n,&m);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d",&a[i].s,&a[i].t);
  }
  sort(a+1,a+n+1,cmp);
  int t = a[1].t, ans = 1;
  if(a[1].s > 1) {
    printf("-1\n");
    return 0;
  }
  for(int i = 2; i <= n; i++) {
    int r = 0;
    if(a[i].s > t) {
      printf("-1\n");
      return 0;
    }
    for(; a[i].s <= t && i <= n; i++) {
      if(a[i].t > r) {
        r = a[i].t;
      }
    }
    if(r > t) {
      t = r;
      ans++;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  if(t < m) {
    printf("-1\n");
  } else {
    printf("%d\n",ans);
  }
  return 0;
}