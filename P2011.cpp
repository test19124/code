#include <bits/stdc++.h>
using namespace std;

long long a,b,k,n,m;
long long x[1010][1010];

int main() {
  cin>>a>>b>>k>>n>>m;
  x[0][1] = 1;
  for(long long i = 1; i <= k; i++) {
    for(long long j = 1; j <= i + 1; j++) {
      x[i][j] = (x[i-1][j-1]*b + x[i-1][j]*a)%10007;
    }
  }
  cout<<x[k][m+1]<<"\n";
  return 0;
}