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
vector<lli> seg(800001);

void build(int low,int high, int i,vector<int>& val){
    if(low==high){
        seg[i]=val[low];
        return;
    }
    lli mid=low+(high-low)/2;
    build(low,mid,i*2+1,val);
    build(mid+1,high,i*2+2,val);
    seg[i]=seg[i*2+1]+seg[i*2+2];
}

lli query(int low,int high, int l,int r,int i){
    if(l>high||r<low|| low>high){
        return 0;
    }
    if(l<=low&&r>=high){
        return seg[i];
    }
    lli mid=low+(high-low)/2;
    lli x=query(low,mid,l,r,i*2+1);
    lli y=query(mid+1,high,l,r,i*2+2);
    return x+y;
}

void act(int low,int high, int i, int val,int l, int r){
    if(high==low && low==l){
        seg[i]=val;
        return ;
    }
    if(l>=low&&r<=high){
        lli mid=low+(high-low)/2;
        act(low,mid,i*2+1,val,l,r);
        act(mid+1,high,i*2+2,val,l,r);
        seg[i]=seg[i*2+1]+seg[i*2+2];
    }
    return ;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,q;
  cin>>n>>q;
  vector<int> values(n);
  fore(i,0,n){
        cin>>values[i];
  }
  build(0,n-1,0,values);
  while(q--){
    int n1;
    cin>>n1;
    if(n1==1){
        int k,u;
        cin>>k>>u;
        act(0,n-1,0,u,k-1,k-1);
    }
    else{
        int a,b;
        cin>>a>>b;
        cout<<query(0,n-1,a-1,b-1,0)<<endl;
    }
  }

  return 0;
}


