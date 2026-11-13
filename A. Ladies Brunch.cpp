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

vector<lli> lazy(400004,0),seg(400004,0);
/*
void build(int low,int high, int i){
    if(low==high){

            return ;
    }
    int mid(low+high)/2;
    build(low,mid,i*2+1);
    build(mid+1,high,i*2+2);
    seg[i]=seg[i*2+1]+seg[i*2+2];
    return;
}*/

lli query(int low, int high,int i, int l, int r){
    if(lazy[i]!=0){
        seg[i]+=lazy[i];
        if(low<high){
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(low==high && low==l){
        return seg[i];
    }
    if(low>r||high<l||low>high){

       return 0;
    }
    int mid=(low+high)/2;
    lli x=query(low,mid,i*2+1,l,r);
    lli y=query(mid+1,high,i*2+2,l,r);

    return x+y;
}

void update(int low, int high, int i, int l, int r, int v){
    if(lazy[i]!=0){
        seg[i]+=lazy[i];
        if(low<high){
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(low>r||high<l||low>high){
        return;
    }
    if(low>=l&&high<=r){
        seg[i]+=v;
        if(low!=high){
            lazy[i*2+1]+=v;
            lazy[i*2+2]+=v;
        }
        return;
    }
    int mid=(low+high)/2;
    update(low,mid,i*2+1,l,r,v);
    update(mid+1,high,i*2+2,l,r,v);
    seg[i]=seg[i*2+1]+seg[i*2+2];
    return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,m;
  cin>>n>>m;
  unordered_map<string,int> per;
  fore(i,0,n){
      string x;
      cin>>x;
      per[x]=i;
  }
  unordered_map<string,int> mp;
  fore(i,0,m){
      string x;
      cin>>x;
      int y;
      cin>>y;
      mp[x]=y;
  }
  int q;
  cin>>q;
  while(q--){
    int a;
    cin>>a;
    if(a==1){
        string s, ss;
        cin>>s>>ss;
        update(0,n-1,0,per[s],per[s],mp[ss]);
    }else if(a==2){
        int x, y;
        string ss;
        cin>>x>>y>>ss;
        if(x<=y)
            update(0,n-1,0,x,y,mp[ss]);
        else{
            update(0,n-1,0,x,n-1,mp[ss]);
            update(0,n-1,0,0,y,mp[ss]);
        }
    }else{
        string s;
        cin>>s;
        cout<<query(0,n-1,0,per[s],per[s])<<endl;
    }
  }


  return 0;
}
