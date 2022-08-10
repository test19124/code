#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long ans;
map <int,map<int,long long>> a;
int d[4][2] = {
  {0,-1},
  {0,1},
  {1,0},
  {-1,0}
};

void f(int x,int y,long long z) {
  ans += z*4;
  for(int i = 0; i < 4; i++) {
    if(a[x][y] < a[x+d[i][0]][y+d[i][1]]) {
      ans -= 2*min(a[x+d[i][0]][y+d[i][1]]-a[x][y],z);
      //printf("- %lld\n",ans);
    }
  }
  a[x][y] += z;
}

int main() {
  scanf("%d",&n);
  int x,y;
  long long z;
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    f(x,y,z);
    printf("%lld\n",ans);
  }
  return 0;
}