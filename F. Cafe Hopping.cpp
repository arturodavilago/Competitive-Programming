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
  lli n,l=0,r=0,res=0,var=0,ndob;
  lli k,Ba;
  cin>>n>>k;
  ndob=n*2;
  vector<lli> a(n);

  Ba=k;

  for(int i=0;i<n;i++){
    cin>>a[i];
  }


  for(int j=0;j<ndob;j++){
if(r==n){
    cout<<res<<endl;
    return 0;
}
    if(a[r]>k)
    {
        Ba=k;
        var=0;
        r++;
        l=r;
    }
    else
    {
    if(Ba>=a[r])
        {
        Ba-=a[r];
        var++;
        res=max(res,var);
        r++;
        }
    else
        {
        Ba+=a[l];
        var--;
        l++;
        }
    }
  }

  cout<<res<<endl;

  return 0;
}
