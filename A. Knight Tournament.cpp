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

vector<int> seg(4000004,0);
/*
void build(int low, int high, int i){
    if(low==high){

        return;
    }
    int mid=(low+high)/2;
    build(low,mid,i*2+1);
    build(mid+1,high,i*2+2);
    seg[i]=seg[i*2+1]seg[i*2+2];
    return;
}*/

int query(int low, int high, int i, int l, int r){
    if(low>r||high<l||low>high){
        return 0;
    }
    if(low>=l&&high<=r){
        return seg[i];
    }
    int mid=low+(high-low)/2;
    int x= query(low,mid,i*2+1,l,r);
    int y =query(mid+1,high,i*2+2,l,r);
    //seg[i]=seg[i*2+1]+seg[i*2+2];
    return x+y;
}

void update(int low, int high, int i, int p){
    if(low==high&&low==p){
        seg[i]++;
        return;
    }
    int mid=low+(high-low)/2;
    if(p<=mid)
    update(low,mid,i*2+1,p);
    else
    update(mid+1,high,i*2+2,p);

    seg[i]=seg[i*2+1]+seg[i*2+2];
    return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n;
  cin>>n;
  vector <int> vec(n),veci(n),vecj(n);
  fore(i,0,n){
    cin>>vec[i];
  }
  unordered_map<int,int> mp;
  fore(i,0,n){
       mp[vec[i]]++;
       veci[i]=mp[vec[i]];
  }
  unordered_map<int,int> mps;
  for(int i=n-1; -1<i; i--){
       mps[vec[i]]++;
       vecj[i]=mps[vec[i]];
  }
  lli ans=0;
  for(int i=n-1; -1<i; i--){
    ans+= query(0,n-1,0,0,veci[i]-1-1);
    update(0,n-1,0,vecj[i]-1);
  }
  cout<<ans<<endl;

  return 0;
}
