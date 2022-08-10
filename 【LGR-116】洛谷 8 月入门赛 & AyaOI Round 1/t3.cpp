#include <bits/stdc++.h>
using namespace std;

int a[1000]; // 将s拆分成二进制
long long b[1000];
long long c[1000];
int d[1000];
long long s,ss;
int m,len,n;
int top;

int main() {
  int T;
  scanf("%d",&T);
  while(T--) {
    scanf("%lld%d",&s,&m);
    ss = s;
    n = 0;
    for(len = 0; ss!=0; len++) {
      a[len] = ss%2;
      ss /= 2;
      if(len == 0) {
        b[len] = 1;
      } else {
        b[len] = b[len-1]*2;
      }
    }
    for(int i = len; i > 0; i--) {
      if(a[i]%2 !=0) {
        a[i]--;
        a[i-1]+=2;
        n += a[i];
      }
    }
    if(a[0]%2 == 1) {
      // 无解
      printf("-1\n");
    } else {
      top = 0;
      for(int i = 0; i < len; i++) {
        if(a[i+1] >= a[i]) {
          c[top] = b[i]+b[i+1];
          d[top] = a[i];
          ++top;
          a[i+1] -= a[i];
          a[i] = 0;
        } else {
          c[top] = b[i]+b[i+1];
          d[top] = a[i+1];
          ++top;
          c[top] = b[i];
          d[top] = a[i]-a[i+1];
          ++top;
          a[i+1] = 0;
          a[i] = 0;
        }
      }
      if(top > m) {
        printf("-1\n");
      } else {
        for(int i = 0; i < top; i++) {
          for(int j = 0; j < d[i]; j++) {
            printf("%lld ",c[i]);
          }
        }
        printf("\n");
      }
    }
  }

  
  /*
  1110 14

  0100 4
  0100 4
  0011 3
  0011 3
  */
  return 0;
}