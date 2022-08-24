#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[210][210];
int b[210][210];
bool vis[210][210];
struct node {
  int x,y;
} man[2],d[4];

void out() {
  printf("\n");
  for(int i = 0; i <= (n+1); i++) {
    for(int j = 0; j <= (m+1); j++) {
      if(a[i][j] == -1) {
        printf(" ###");
      } else if(b[i][j] == 998244353) {
        printf(" % 2d<",a[i][j]);
      } else {
        printf(" % 3d",b[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

node tonode(int x,int y) {
  node k;
  k.x = x;
  k.y = y;
  return k;
}

void f(int x,int y) {
  queue<node> q;
  q.push(tonode(x,y));
  while(!q.empty()) {
    node k = q.front();
    q.pop();
    //out();
    int xx = k.x, yy = k.y;
    for(int i = 0; i < 4; i++) {
      if((vis[xx+d[i].x][yy+d[i].y] == 0) && (!(((xx+d[i].x) == man[1].x) && ((yy+d[i].y) == man[1].y)))) {
        b[xx+d[i].x][yy+d[i].y] = min(b[xx+d[i].x][yy+d[i].y],b[xx][yy] + a[xx+d[i].x][yy+d[i].y]);
        vis[xx+d[i].x][yy+d[i].y] = 1;
        if(((xx+d[i].x) <= n) && ((xx+d[i].x) >= 1) && ((yy+d[i].y) <= m) && ((yy+d[i].y) >= 1)) {
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

  scanf("%d%d",&n,&m);
  string str;
  char ch;
  for(int i = 1; i <= n; i++) {
    cin>>str;
    for(int j = 1; j <= m; j++) {
      ch = str[j-1];
      b[i][j] = 998244353;
      if(ch == '#') {
        vis[i][j] = -1;
        a[i][j] = -1;
      }
      if(ch == '.') {
        a[i][j] = 1;
      }
      if(ch == 'G') {
        a[i][j] = 2;
      }
      if(ch == 'M') {
        a[i][j] = 1;
        man[0].x = i;
        man[0].y = j;
      }
      if(ch == '@') {
        man[1].x = i;
        man[1].y = j;
      }
    }
  }

  b[man[1].x][man[1].y] = 0;
  f(man[1].x,man[1].y);

  printf("%d\n",b[man[0].x][man[0].y]);

  return 0;
}