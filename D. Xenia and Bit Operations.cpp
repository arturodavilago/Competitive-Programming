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

vector<int> seg(4*131076);

void build(int low, int high, int i, int x, vector<int>& vec){
    x++;
    x=x%2;
    if(x==0){
        if(low==high){
            seg[i] = vec[low];
            return;
        }
        int mid=(low+high)/2;
        build(low,mid,i*2+1,x,vec);
        build(mid+1,high,i*2+2,x,vec);
        seg[i]=seg[i*2+1]^seg[i*2+2];
    }
    else{
        int mid=(low+high)/2;
        build(low,mid,i*2+1,x,vec);
        build(mid+1,high,i*2+2,x,vec);
        seg[i]=seg[i*2+1]|seg[i*2+2];
    }
}

void query(int low,int high,int i, int x,int l, int v){
    x++;
    x=x%2;
    if(low>l||high<l||low>high){
        return;
    }
    if(low>=l&&high<=l){
        seg[i]=v;
        return;
    }
    if(x==0){
        int mid=(low+high)/2;
        query(low,mid,i*2+1,x,l,v);
        query(mid+1,high,i*2+2,x,l,v);
        seg[i]=seg[i*2+1]^seg[i*2+2];
        return;
    }
    else{
        int mid=(low+high)/2;
        query(low,mid,i*2+1,x,l,v);
        query(mid+1,high,i*2+2,x,l,v);
        seg[i]=seg[i*2+1]|seg[i*2+2];
        return;
    }
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,m;
  cin>>n>>m;
  int ncuadrardas=1;
  for(int i=0;i<n;i++){
    ncuadrardas*=2;
  }
  vector<int> vec(ncuadrardas);
  fore(i,0,ncuadrardas){
        cin>>vec[i];
  }


  if(n&1){
    build(0,ncuadrardas-1,0,0,vec);
    while(m--){
        int p,b;
        cin>>p>>b;
        query(0,ncuadrardas-1,0,0,p-1,b);
        cout<<seg[0]<<endl;
  }
  }
  else{
    build(0,ncuadrardas-1,0,1,vec);
    while(m--){
        int p,b;
        cin>>p>>b;
        query(0,ncuadrardas-1,0,1,p-1,b);
        cout<<seg[0]<<endl;
  }
  }


  return 0;
}
