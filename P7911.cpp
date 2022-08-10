#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
  int ip[4]; // IP地址
  string strip[4];
  int port;  // 端口
  string strport;
  bool istrue; // 此地址是否有效
  string host[2];
  bool isserver;
} a[1010];
int tot;

void init(int i) {
  a[i].ip[0] = 0;
  a[i].ip[1] = 0;
  a[i].ip[2] = 0;
  a[i].ip[3] = 0;
  a[i].strip[0] = "";
  a[i].strip[1] = "";
  a[i].strip[2] = "";
  a[i].strip[3] = "";
  a[i].port = 0;
  a[i].strport = "";
  a[i].istrue = true;
  a[i].host[0] = "";
  a[i].host[1] = "";
  a[i].isserver = false;
}

bool add(string str,bool isserver) {
  int len = str.length();
  int dian = 0,mao = 0, ip = 0;
  bool isport = false;
  for(int i = 0; i < len; i++) {
    if(str[i] == '.') {
      dian++;
    }
    if(str[i] == ':') {
      mao++;
      if(dian != 3) {
        return false;
      }
    }
  }
  if(mao != 1 || dian != 3) {
    return false;
  }
  init(tot);
  a[tot].host[1] = str;
  a[tot].isserver = isserver;
  int lenip = 0,lenport = 0;
  for(int i = 0; i < len; i++) {
    if(str[i] == ':') {
      isport = true;
    } else {
      if(!isport) {
        if(str[i] == '.') {
          ip++;
        } else {
          a[tot].ip[ip] *= 10;
          a[tot].ip[ip] += int(str[i] - '0');
          a[tot].strip[ip] += str[i];
        }
        lenip++;
        a[tot].host[0] += str[i];
        if(lenip > 15) {
          return false;
        }
      } else {
        lenport++;
        a[tot].port *= 10;
        a[tot].port += int(str[i] - '0');
        a[tot].strport += str[i];
        if(lenport > 6) {
          return false;
        }
      }
    }
  }
  a[tot].istrue = true;
  for(int i = 0; i < 4; i++) {
    if(!(a[tot].ip[i]>=0&&a[tot].ip[i]<=255)) {
      a[tot].istrue = false;
    }
    if(a[tot].strip[i].length() > 1 && a[tot].strip[i][0] == '0') { // 有前导0
      a[tot].istrue = false;
    }
    if(a[tot].strip[i].length() == 0) {
      a[tot].istrue = false;
    }
  }
  if(!(a[tot].port>=0&&a[tot].port<=65535)) {
    a[tot].istrue = false;
  }
  if(a[tot].strport.length() > 1 && a[tot].strport[0] == '0') { // 有前导0
    a[tot].istrue = false;
  }
  if(a[tot].strport.length() == 0) {
    a[tot].istrue = false;
  }
  if(a[tot].istrue) {
    tot++;
    return a[tot-1].istrue;
  } else {
    return a[tot].istrue;
  }
}

map <string,int> mp;

int main() {
  scanf("%d",&n);
  string a,b;
  for(int i = 0; i < n; i++) {
    cin>>a>>b;
    if(a == "Server") {
      if(add(b,true)) { // 符合规范
        if(mp[b] == 0) { // 还未建立连接
          mp[b] = i+1;
          printf("OK\n");
        } else {
          printf("FAIL\n");
        }
      } else {
        printf("ERR\n");
      }
    } else if(a == "Client") {
      if(add(b,true)) { // 符合规范
        if(mp[b] == 0) { // 服务器不存在
          printf("FAIL\n");
        } else {
          printf("%d\n",mp[b]);
        }
      } else {
        printf("ERR\n");
      }
    }
  }
  return 0;
}