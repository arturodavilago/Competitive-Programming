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

int main() {cin.tie(0)->sync_with_stdio(0), cout.tie(0);
      int n,d;
      cin>>n>>d;
      vector<pair<int,int>> vec(n);
      for(int i=0;i<n;i++){
            cin>>vec[i].first>>vec[i].second;
      }
      sort(vec.begin(),vec.end());
      long long curr=0,l=0,r=0, ans=0;
      while(l<=r && r<n){
            while(l<r && vec[l].first+d-1<vec[r].first){
                curr-=vec[l].second;
                l++;
            }
            curr+=vec[r].second;
            r++;
            ans=max(ans,curr);
      }
      cout<<ans<<endl;


  return 0;
}
