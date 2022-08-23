#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1010][1010][2];
struct node {
  int x,y;
} jidi[1010],man[2],d[4];
int tot;

node tonode(int x,int y) {
  node k;
  k.x = x;
  k.y = y;
  return k;
}

void out(int k) {
  printf("\n");
  for(int i = 0; i <= (n+1); i++) {
    for(int j = 0; j <= (m+1); j++) {
      printf(" % 3d",a[i][j][k]);
    }
    printf("\n");
  }
  printf("\n");
}

void addjidi(int x,int y) {
  tot++;
  jidi[tot].x = x;
  jidi[tot].y = y;
}

queue<node> q;

void f(int x,int y,int k) {
  while(!q.empty()) {
    q.pop();
  }
  q.push(tonode(x,y));
  while(!q.empty()) {
    node b = q.front();
    //printf("<-\n");
    q.pop();
    int xx = b.x;
    int yy = b.y;
    for(int i = 0; i < 4; i++) {
      //printf("<--- %d | %d %d | %d %d\n",a[xx+d[i].x][yy+d[i].y][k],xx+d[i].x,man[k].x,yy+d[i].y,man[k].y);
      if((a[xx+d[i].x][yy+d[i].y][k] == 0) && (!(((xx+d[i].x) == man[k].x) && ((yy+d[i].y) == man[k].y)))) {
        //printf("<-----\n");
        a[xx+d[i].x][yy+d[i].y][k] = a[xx][yy][k] + 1;
        if(((xx+d[i].x) <= n) && ((xx+d[i].x) >= 1) && ((yy+d[i].y) <= m) && ((yy+d[i].y) >= 1)) {
          //printf("<-------\n");
          q.push(tonode(xx+d[i].x,yy+d[i].y));
        }
      }
    }
  }
}

int main() {
  
  d[1] = tonode(1,0);
  d[2] = tonode(0,1);
  d[3] = tonode(0,-1);
  d[0] = tonode(-1,0);

/*
  for(int i = 0; i < 4; i++) {
    printf("(%d,%d) ",d[i].x,d[i].y);
  }
  printf("\n");
*/

  scanf("%d%d",&n,&m);
  string str;
  char ch;
  for(int i = 1; i <= n; i++) {
    cin>>str;
    for(int j = 1; j <= m; j++) {
      ch = str[j-1];
      if(ch == '.') {
        a[i][j][0] = a[i][j][1] = 0;
      }
      if(ch == '#') {
        a[i][j][0] = a[i][j][1] = -1;
      }
      if(ch == '@') {
        man[0].x = i;
        man[0].y = j;
      }
      if(ch == '&') {
        man[1].x = i;
        man[1].y = j;
      }
      if(ch == 'F') {
        addjidi(i,j);
      }
    }
  }
  
  //printf("%d %d\n%d %d\n\n",man[0].x,man[0].y,man[1].x,man[1].y);

  f(man[0].x,man[0].y,0);
  f(man[1].x,man[1].y,1);

  int ans = 998244353;
  for(int i = 1; i <= tot; i++) {
    if(a[jidi[i].x][jidi[i].y][0] != 0 && a[jidi[i].x][jidi[i].y][1] != 0) {
      ans = min(ans, a[jidi[i].x][jidi[i].y][0] + a[jidi[i].x][jidi[i].y][1]);
    }
  }
  if(ans == 998244353) {
    printf("-1\n");
  } else {
    printf("%d\n",ans);
  }

  //out(0);
  //out(1);

  return 0;
}