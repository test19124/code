#include <bits/stdc++.h>
using namespace std;

string a;
stack<double> st;

int num(int &i) {
  int x = 0;
  while(1) {
    if(a[i] < '0' || a[i] >'9') {
      break;
    }
    x *= 10;
    x += int(a[i] - '0');
    i++;
  }
  return x;
}

/*
double get(int &i) {
  if(a[i] == ')') {
    i++;
  }
  double x,y,z;
  int k = -1;
  if(a[i] == '(') {
    i++;
    x = get(i);
  } else {
    x = num(i);
  }
  if(a[i+1] == '(') {
    k = i+2;
    y = get(k);
  } else {
    k = i+1;
    y = num(k);
  }
  if(x == -114514.1919810 || y == -114514.1919810) {
    return -114514.1919810;
  }
  if(a[i] == '+') {
    z = x+y;
  }
  if(a[i] == '-') {
    z = x-y;
  }
  if(a[i] == '*') {
    z = x*y;
  }
  if(a[i] == '/') {
    if(y == 0) {
      return -114514.1919810;
    }
    z = x/y;
  }
  if(k != -1) {
    i = k;
  }
  return z;
}
*/

int get(int i) {
  while(a[i] != ')') {
    if(a[i] == '(') {
      i = get(i+1);
    }

    st.push(num(i));

    if(a[i] == '+') {
      int x = st.top();
      st.pop();
      
    }
  }
}

int main() {
  cin>>a;
  int i = 0;
  return 0;
}