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
  int n,k;
  cin>>n>>k;
  vector<int> vec(n),vecsort(n);
  fore(i,0,n){
        cin>>vec[i];
        vecsort[i]=vec[i];
  }
  sort(vecsort.begin(),vecsort.end());

  unordered_map<int,int> mp;
  lli ans=0;
  for(int i=n-1;i>=n-k;i--){
        ans+=vecsort[i];
        if(mp[vecsort[i]>1]){
            mp[vecsort[i]]+=1;
        }
        else{
        mp[vecsort[i]]++;
        }
  }
  cout<<ans<<endl;
  vector<int> an(k);
  int j=0;
  bool b=false;
  int r=1,c=0;
  for(int i=0;i<n;i++){
        if(mp.count(vec[i])){
            if(mp[vec[i]]>0){
                c++;
                if(c==2){
                    an[j]=r-1;
                    c=1;
                    r=1;
                    j++;
                }
                mp[vec[i]]-=1;
            }

        }
        if(i==n-1){
            an[k-1]=r;
        }
        r++;
  }
  for(int i=0;i<k;i++){
        cout<<an[i]<<" ";
  }
  cout<<endl;




  return 0;
}
