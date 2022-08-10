#include <bits/stdc++.h>
using namespace std;

int n;
int fa[200010];

int f(int x,int &y) {
  y++;
  if(fa[x] == x) {
    return x;
  }
  return f(fa[x],y);
}

int main() {
  scanf("%d",&n);
  for(int i = 1; i <= n; i++) {
    fa[i]=i;
  }
  int x,y;
  int ans = 998244353;
  for(int i = 1; i <= n; i++) {
    scanf("%d",x);
    y = 0;
    if(f(x,y) == i) {
      ans = min(ans, y);
    } else {
      fa[i] = x;
    }
  }
  printf("%d",ans);
  return 0;
}