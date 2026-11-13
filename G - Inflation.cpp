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
    int n,k;
    cin>>n>>k;
    vector<lli> vec(n);
    fore(i,0,n){
        cin>>vec[i];
    }

    lli ans=0;
    fore(i,0,n-1){
        lli l=vec[i],r=(vec[i+1] * 100LL + k - 1) / k;
        if(r*100LL>k*l){
            r+=l;
            while(true){

                lli mid=l+((r-l)/2);

                if(r==l){

                    vec[i+1]+=r;
                    ans+=r-vec[i];
                    break;
                }


                else if(vec[i+1]*100LL<=k*mid){

                    r=mid;
                }
                else if((vec[i+1]*100LL)>k*mid){
                    l=mid+1;

                }

            }
        }
        else{
        vec[i+1]=vec[i]+vec[i+1];
        }
    }
    cout<<ans<<endl;


  }
  return 0;
}
