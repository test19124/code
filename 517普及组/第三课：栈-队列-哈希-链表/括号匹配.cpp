#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
  string str;
  cin>>str;
  int len = str.length();
  for(int i = 0; i < len; i++) {
    if(str[i] == ')') {
      printf("%d %d\n",st.top(),i);
      st.pop();
    } else {
      st.push(i);
    }
  }
  return 0;
}