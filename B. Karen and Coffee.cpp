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
  int n,x,q;
  cin>>n>>x>>q;
  vector<lli> vec(200050,0);
  vector<int> pre(200050,0);
  fore(i,0,n){
    int l,r;
    cin>>l>>r;
    vec[l]++;
    vec[r+1]--;
  }
  lli ac=0;
  fore(i,0,vec.size()){
    ac+=vec[i];
    vec[i]=ac;
    if(vec[i]>=x){
        if(pre[i+1]<1){
            pre[i+1]++;
        }
    }
  }
  lli v=0;

  fore(i,0,vec.size()){
    v+=pre[i];
    pre[i]=v;
  }

  fore(i,0,q){
    int le,ri;
    cin>>le>>ri;
    int ans;
    ans=pre[ri+1]-pre[le];
    cout<<ans<<endl;
  }



  return 0;
}
