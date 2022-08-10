#include <bits/stdc++.h>
using namespace std;

char a[50]={'A','2','3','4','5','6','7','8','9','T','J','Q','K','X','D'};
map <char,int> b;

int main() {
  int n;
  cin>>n;
  for(int i = 0; i < n; i++) {
    string str;
    bool jiao = false, zhaX = false, zhaD = false;
    cin>>str;
    for(int j = 0; j < 17; j++) {
      b[str[j]]++;
      if(str[j]=='X') {
        zhaX = true;
      }
      if(str[j]=='D') {
        zhaD = true;
      }
    }
    if(zhaD && zhaX) {
      for(int j = 0; j < 15; j++) {
        b[a[j]] = 0;
      } 
      printf("yes\n");
    } else {
      for(int j = 0; j < 15; j++) {
        if(b[a[j]]>=4) {
          jiao = true;
        }
        //printf("%c:%d ",a[j],b[a[j]]);
        b[a[j]] = 0;
      }
      if(jiao) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}