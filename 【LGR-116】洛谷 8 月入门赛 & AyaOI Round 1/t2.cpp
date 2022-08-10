#include <bits/stdc++.h>
using namespace std;

int a[10],b[20],c;

int main() { 
  int n;
  cin>>n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++) {
      cin>>a[j];
      if(b[a[j]] == 0) {
        c++;
      }
      b[a[j]]++;
    }
    sort(a,a+4);
    /*
    for(int j = 0; j < 4; j++) {
      printf("%d ",a[j]);
    }
    */
    bool flag = false;

    if(a[0]+1 == a[1] && a[1] == a[2]-1) {
      flag = true;
    } else if(a[0]+1 == a[1] && a[1] == a[3]-1) {
      flag = true;
    } else if(a[0]+1 == a[2] && a[2] == a[3]-1) {
      flag = true;
    } else if(a[1]+1 == a[2] && a[2] == a[3]-1) {
      flag = true;
    }

    for(int j = 0; j < 4; j++) {
      for(int k = j + 1; k < 4; k++) {
        if((((a[j]+1) == a[k]) || ((a[j]+2) == a[k])) && ((b[a[j]]==1) && (b[a[k]]==1) && (c == 3) || (b[a[j]]==3) && (b[a[k]]==1) && (c == 2) || (b[a[j]]==1) && (b[a[k]]==3) && (c == 2))) {
          flag = true;
          break;
        }
        //printf("  %d %d %d %d\n",a[j],a[k],b[a[j]],b[a[k]]);
      }
    }
    if(flag) {
      printf("1\n");
    } else {
      printf("0\n");
    }
    for(int j = 0; j < 10; j++) {
      //printf("%d ",b[j]);
      b[j] = 0;
      c = 0;
    }
    //printf("\n");
  }
  return 0;
}