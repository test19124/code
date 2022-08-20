#include <bits/stdc++.h>
using namespace std;

struct node {
  int id; // 学生编号
  int kid; // 班级号
  int to; // 队列的下一个
} a[500010];
int front = 1, tot = 0; // 队列头部
int kc[100010]; // 每个班人数

int find(int kid) {
  int i = front;
  if(a[i].kid == kid) {
    return -2; // 在头部添加
  }
  while(1) {
    if(a[a[i].to].kid == kid) { // 该人是kid班级的人
      return i;
    }
    if(a[i].to == 0) {
      break;
    }
    i = a[i].to;
  }
  return -1; // 没有kid班级的人
}

int push(int id,int k,int nxt = tot) {
  tot++;
  a[tot].id = id;
  a[tot].kid = k;
  if(nxt == -2) {
    a[tot].to = front;
    front = tot;
  } else {
    a[tot].to = a[nxt].to;
    a[nxt].to = tot; 
  }
  kc[k]++;
  return tot;
}

void printlist() {
  int i = front;
  while(1) {
    printf("(%d,%d,%d)->",i,a[i].id,a[i].kid);
    if(a[i].to == 0) {
      break;
    }
    i = a[i].to;
  }
  printf("\n");
}

int pop() {
  int id = a[front].id;
  kc[a[front].kid]--;
  front = a[front].to;
  return id;
}

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  int a,b;
  for(int i = 1; i <= n; i++) {
    scanf("%d%d",&a,&b);
    push(a,b);
  }
  //printlist();
  int m;
  scanf("%d",&m);
  int x;
  for(int i = 1; i <= m; i++) {
    scanf("%d",&x);
    if(x == 1) {
      scanf("%d%d",&a,&b);
      if(kc[b] == 0) {
        push(a,b);
      } else {
        push(a,b,find(b));
      }
    } else {
      printf("%d\n",pop());
    }
    //printlist();
  }
  return 0;
}