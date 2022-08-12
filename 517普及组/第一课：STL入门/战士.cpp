#include <bits/stdc++.h>
using namespace std;

map <int,int> mp[100010];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  int x,y,z;
  for(int i = 1; i <= m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    if(x == 1) {
      mp[y][++mp[y][0]] = z;
    } else {
      printf("%d\n",mp[y][z]);
    }
  }
  return 0;
}