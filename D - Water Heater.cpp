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
  int n, x;
  cin>>n>>x;
  vector<lli> vec(200001, 0);
  fore(i,0,n){
    int s,t,p;
    cin>>s>>t>>p;
    vec[s]+=p;
    vec[t]-=p;
  }
  lli ac=0;
  fore(i,0,n){
    ac+=vec[i];
    if(ac>x){
        cout<<"No"<<endl;
        return 0;
    }
  }
  cout<<"Yes"<<endl;


  return 0;
}
