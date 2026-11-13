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

vector<set<int>> seg(4*200005);
vector<int> vec(200005);

void build(int i, int low, int high){
    if(low == high){
        seg[i].insert(vec[low]) ;
        return;
    }
    int m = (high+low)/2;
    build(2*i+1, low, m);
    build(2*i+2, m+1, high);
    seg[i].insert(all(seg[2*i+1]));
    seg[i].insert(all(seg[2*i+2]));
}

set<int> ans(int i, int low, int high, int l, int r){
    if(r<low||l>high||low>high){
        set<int> st;
        return st;
    }
    if(low>=l&&high<=r){
        return seg[i];
    }

    int mid=(high+low)/2;
    set<int> x=ans(i*2+1,low,mid,l,r);
    set<int> y=ans(i*2+2,mid+1,high,l,r);
    //seg[i].insert(all(seg[2*i+1]));
    //seg[i].insert(all(seg[2*i+2]));
    x.insert(all(y));
    return x;
}



int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,q;
  cin>>n>>q;
  fore(i,0,n){
      cin>>vec[i];
  }
  build(0,0,n-1);
  while(q--){
        int a,b;
        cin>>a>>b;
        cout<<ans(0,0,n-1,a,b).size()<<endl;

  }

  return 0;
}
