#include <bits/stdc++.h>
using namespace std;

char a[6][8] = {
  "..+---+",
  "./   /|",
  "+---+ |",
  "|   | +",
  "|   |/.",
  "+---+.."
};
char b[1010][1010];
int x[60][60];
int n,m;
int nn,mm;
int maxx,maxy;

void draw(int y,int x,int z) {
  int xx = x*4+y*2;
  int yy = y*2+z*3;
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      if(a[5-i][j]!='.') {
        b[xx+j][yy+i] = a[5-i][j];
      }
      maxx = max(maxx, xx+j);
      maxy = max(maxy, yy+i);
    }
  }
}

void putout() {
  for(int j = maxy; j >= 0; j--) {
    for(int i = 0; i <= maxx; i++) {
      printf("%c",b[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  scanf("%d%d",&n,&m);
  for(int i = 0; i < 1010; i++) {
    for(int j = 0; j < 1010; j++) {
      b[i][j]='.';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d",&x[i][j]);
    }
  }
  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < x[n-i-1][j]; k++) {
        draw(i,j,k);
      }
      //putout();
    }
  }
  putout();
  return 0;
}