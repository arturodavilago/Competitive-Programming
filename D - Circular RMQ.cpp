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

vector<lli>  seg(4000008),lazy(4000008);

void build(lli low,lli high, lli i,vector<lli>& vec){
    if(low==high){
        seg[i]=vec[low];
        return;
    }
    lli mid=(low+high)/2;
    build(low,mid,i*2+1,vec);
    build(mid+1,high,i*2+2,vec);
    seg[i]=min(seg[i*2+1],seg[i*2+2]);
}

lli query(lli low, lli high, lli i, lli l, lli r){
    if(lazy[i]!=0){
        if(low!=high){
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        seg[i]+=lazy[i];
        lazy[i]=0;
    }
    if(low>r||high<l||low>high){
        return LLONG_MAX;
    }
    if(low>=l&&high<=r){
        return seg[i];
    }
    lli mid=(high+low)>>1;
    lli x=query(low,mid,i*2+1,l,r);
    lli y=query(mid+1,high,i*2+2,l,r);
    seg[i]=min(seg[i*2+1],seg[i*2+2]);
    return min(x,y);
}

void act(lli low, lli high,lli i, lli l, lli r, lli val){
    if(lazy[i]!=0){
        if(low!=high){
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        seg[i]+=lazy[i];
        lazy[i]=0;
    }
    if(low>r||high<l||low>high){
        return;
    }
    if(low>=l&&high<=r){
        seg[i]+=val;
        if(low!=high){
        lazy[i*2+1]+=val;
        lazy[i*2+2]+=val;
        }
        return;
    }
    lli mid=(low+high)>>1;
    act(low,mid,i*2+1,l,r,val);
    act(mid+1,high,i*2+2,l,r,val);
    seg[i]=min(seg[i*2+1],seg[i*2+2]);
    return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  lli n;
  cin>>n;
  vector<lli> vec(n);
  fore(i,0,n){
    cin>>vec[i];
  }
  build(0,n-1,0,vec);
  lli t;
  cin>>t;
  cin.ignore();
  while(t--){
    lli l,r,x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss>>l>>r;
    if(ss>>x){
        if(r>=l)
            act(0,n-1,0,l,r,x);
        else{
            act(0,n-1,0,0,r,x);
            act(0,n-1,0,l,n-1,x);
        }
    }
    else{
        if(r>=l)
            cout<<query(0,n-1,0,l,r)<<endl;
        else{
            cout<<min(query(0,n-1,0,0,r),query(0,n-1,0,l,n-1))<<endl;
        }

    }
  }

    return 0;
}
