#include <bits/stdc++.h>
using namespace std;

int n,x,y;
int a[100010];
int b[100010];
int g[100010];
int k[100010];

int main() {
  scanf("%d",&n);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
  }
  scanf("%d%d",&x,&y);
  for(int i = n; i >= 0; i--) {
    if(a[i]<=x&&b[i]<=y&&x<=(a[i]+g[i])&&y<=(b[i]+k[i])) {
      printf("%d",i);
      return 0;
    }
  }
  printf("-1");
  return 0;
}