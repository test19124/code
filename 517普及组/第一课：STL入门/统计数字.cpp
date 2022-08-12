#include <bits/stdc++.h>
using namespace std;

map <int,int> mp;

int main() {
  int n;
  scanf("%d",&n);
  int x;
  for(int i = 1; i <= n; i++) {
    scanf("%d",&x);
    mp[x]++;
  }
  int a = -1;
  for(map<int,int>::iterator i = mp.begin(); i != mp.end(); i++) {
    if(i->second > a) {
      a = i->second;
    }
  }
  for(map<int,int>::iterator i = mp.begin(); i != mp.end(); i++) {
    if(i->second == a) {
      printf("%d ",i->first);
    }
  }
  return 0;
}