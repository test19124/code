#include <bits/stdc++.h>
using namespace std;

int n,y;
string x;
multiset<int>a;

int main() {
  scanf("%d",&n);
  while(n--) {
    cin>>x>>y;
    if(x == "Push") {
      a.insert(y);
    } else if(x == "Pop") {
      multiset<int>::iterator b = a.upper_bound(y);
      if(b != a.begin()) {
        b--;
        printf("%d\n",*b);
        a.erase(a.find(*b));
      } else {
        printf("No Element!\n");
      }
    }
  }
  return 0;
}