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
#define debx(...) (_VA_ARGS_)
#ifdef LOCAL
#include "debug.h"
#endif
using ld = long double;
using lli = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n, q;
  cin>>n>>q;
  vector<int> vec(n+1);
  vec[n]=0;
  vector<lli> pre(n+1,0);
  fore(i,0,n){
        int m;
        cin>>m;
        vec[i]=m;

  }

  fore(i,0,q){
        int l,r;
        cin>>l>>r;
        pre[l-1]++;
        pre[r]--;

  }
  lli v=0;
  fore(i,0,n){
        v+=pre[i];
        pre[i]=v;
  }

  sort(vec.begin(),vec.end());
  sort(pre.begin(),pre.end());

  lli ac=0;
  fore(i,0,n+1){
    ac=ac+(vec[i]*pre[i]);

  }
  cout<<ac<<endl;

  return 0;
}
