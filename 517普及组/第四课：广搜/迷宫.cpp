#include <bits/stdc++.h>
using namespace std;

int n,m;
int tox,toy;
//bool vis[20][510];
//int minn = 998244353;

int vis[20][510];
queue<pair<int,int>> q;

/*
void f(int x,int y,int z) {
  if(x < 1 || x > n || y < 1 || y > m) {
    return;
  }
  if(x == tox && y == toy) {
    if(z < minn) {
      minn = z;
    }
    return;
  }
  if(vis[x+1][y]!=1) {
    vis[x+1][y] = 1;
    f(x+1,y,z+1);
    vis[x+1][y] = 0;
  }
  if(vis[x][y+1]!=1) {
    vis[x][y+1] = 1;
    f(x,y+1,z+1);
    vis[x][y+1] = 0;
  }
  if(vis[x-1][y]!=1) {
    vis[x-1][y] = 1;
    f(x-1,y,z+1);
    vis[x-1][y] = 0;
  }
  if(vis[x][y-1]!=1) {
    vis[x][y-1] = 1;
    f(x,y-1,z+1);
    vis[x][y-1] = 0;
  }
}
*/

void out(int x = -1, int y = -1) {
  for(int i = 0; i <= n+1; i++) {
    for(int j = 0; j <= m+1; j++) {
      if(x == i && y == j) {
        printf("  &");
      } else {
        printf("% 3d",vis[i][j]);
      }
    }
    printf("\n");
  }
  printf("---------\n");
}

void f(int xx,int yy) {
  vis[xx][yy] = 1;
  q.push(make_pair(xx,yy));
  while(!q.empty()) {
    pair<int,int> k = q.front();
    q.pop();
    int x = k.first;
    int y = k.second;
    //out(x,y);
    if(x < 1 || x > n || y < 1 || y > m) {
      continue;
    }
    if(x == tox && y == toy) {
      break;
    }
    if(vis[x+1][y] == 0) {
      vis[x+1][y] = vis[x][y]+1;
      q.push(make_pair(x+1,y));
    }
    if(vis[x][y+1] == 0) {
      vis[x][y+1] = vis[x][y]+1;
      q.push(make_pair(x,y+1));
    }
    if(vis[x-1][y] == 0) {
      vis[x-1][y] = vis[x][y]+1;
      q.push(make_pair(x-1,y));
    }
    if(vis[x][y-1] == 0) {
      vis[x][y-1] = vis[x][y]+1;
      q.push(make_pair(x,y-1));
    }
  }
}

int main() {
  //cin>>n>>m;
  scanf("%d%d",&n,&m);
  int x,y;
  char ch;
  //string a;
  for(int i = 1; i <= n; i++) {
    //cin>>a;
    scanf("%c",&ch);
    for(int j = 0; j < m; j++) {
      scanf("%c",&ch);
      if(ch /*a[j]*/ == 'S') {
        x = i;
        y = j+1;
      }
      if(ch /*a[j]*/ == 'T') {
        tox = i;
        toy = j+1;
      }
      if(ch /*a[j]*/ == '#') {
        vis[i][j+1] = -1;
      }
    }
  }
  //f(x,y,0);
  f(x,y);
  //cout<<minn<<"\n";
  printf("%d\n",vis[tox][toy]-1);
  return 0;
}