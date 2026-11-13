#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,inline")
#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r)  \
for (auto i = (l) - ((l) > (r)); \
          i != (r) - ((l) > (r)); \
          i += 1 - 2 * ((l) > (r)))
#define sz(x) int((x).size())
#define all(x) begin((x)), end((x))

#define debug(...)
#define debx(...) (__VA_ARGS__)
#ifdef LOCAL
#include "debug.h"
#endif
using ld = long double;
using lli = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> vec(n+1);
  vec[0]=0;
  fore(i,1,n+1){

    cin>>vec[i];
  }
  vector<vector<lli>> pre(m+1,vector<lli>(3));
  fore(i,1,m+1){

    cin>>pre[i][0]>>pre[i][1]>>pre[i][2];
  }

  vector<lli> ran(m+2,0);
  fore(i,1,k+1){
    int l,r;
    cin>>l>>r;
    ran[l]++;
    ran[r+1]--;

  }
  lli ac=0;
  fore(i,1,m+1){

    ac+=ran[i];
    ran[i]=ac;
    pre[i][2]=pre[i][2]*ran[i];
  }
  vector<lli> pre2(n+2,0);
  fore(i,1,m+1){

    pre2[pre[i][0]]+=pre[i][2];
    pre2[pre[i][1] + 1]-=pre[i][2];
  }
  lli ac2=0;
  fore(i,1,n+1){

    ac2+=pre2[i];
    pre2[i]=ac2;
  }

  fore(i,1,n+1){

    pre2[i]+=vec[i];
  }

  fore(i,1,n+1){

    cout<<pre2[i]<<endl;
  }

  return 0;
}
