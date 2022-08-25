#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  map<string,int> a;
  string x;
  int y;
  while(n--) {
    cin>>x>>y;
    a[x] += y;
  }
  printf("%d\n",a.size());
  for(map<string,int>::iterator i = a.begin(); i != a.end(); i++) {
    printf("%s %d\n",i->first.c_str(),i->second);
  }
  return 0;
}