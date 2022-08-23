#include <bits/stdc++.h>
using namespace std;

struct node {
  int l,r;
} a[1010];

void f(int i) {
  printf("%d ",i);
  if(a[i].l != 0) {
    f(a[i].l);
  }
  if(a[i].r != 0) {
    f(a[i].r);
  }
}

queue<int> q;

int main() {
  int n;
  scanf("%d",&n);
  int x,y,z;
  for(int i = 1; i <= n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    a[x].l = y;
    a[x].r = z;
  }
  //f(1);
  q.push(1);
  while(!q.empty()) {
    int i = q.front();
    q.pop();
    printf("%d ",i);
    if(a[i].l != 0) {
      q.push(a[i].l);
    }
    if(a[i].r != 0) {
      q.push(a[i].r);
    }
  }
  return 0;
}