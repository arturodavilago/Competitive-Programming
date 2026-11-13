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
const lli MOD=1000000007;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n, x;
  cin>>n>>x;
  vector<unsigned long long> vec(n),dp(x+1,0);
    dp[0]++;
  fore(i,0,n){
      cin>>vec[i];
  }
  sort(all(vec));
/*
  for(int v: vec){
    fore(i, v,x+1){
        dp[i]=;
    }
  }*/

  for(int i=0;i<n;i++){
    for(int j=vec[i];j<=x;j++){
        dp[j]+=(dp[j-vec[i]])%MOD;
    }
  }
  cout<<dp[x]%MOD<<endl;



  return 0;
}
