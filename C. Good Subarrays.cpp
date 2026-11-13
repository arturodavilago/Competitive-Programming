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
  int t;
  cin>>t;
  while(t--){
    lli n,pre=0,ans=0;
    string s;
    map<lli,lli> mp;
    cin>>n;
    cin>>s;
    vector<lli> vec;
    vec.push_back(0);
    mp[0]=1;

    for(lli i=0;i<n;i++){
        vec.push_back(s[i]-'0');
    }


    for(lli i=1;i<=n;i++){
        pre=pre+vec[i]-1;
        ans += mp[pre];
        mp[pre]++;
    }
    cout<<ans<<endl;
  }

  return 0;
}
