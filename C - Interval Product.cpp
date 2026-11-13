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

void build(int low, int high, int i, vector<int>& vec, vector<int>& seg){
    if(low==high){
        if(vec[low] > 0)
            seg[i]=1;
        else if(vec[low] < 0)
            seg[i]=-1;
        else
            seg[i]=0;
        return;
    }
    int m = low +(high-low)/2;
    build(low, m, i*2+1, vec,seg);
    build(m+1, high, i*2+2, vec,seg);
    seg[i] = seg[i*2+1] * seg[i*2+2];
}

void act(int low, int high, int i, int p, int val, vector<int>& seg){
    if(low==high && low==p){
        seg[i] = val;
        return;
    }
    if(p>high || p<low || low>high){
        return;
    }
    int m = low +(high-low)/2;
    act(low,m,i*2+1,p,val,seg);
    act(m+1,high,i*2+2,p,val,seg);
    seg[i] = seg[i*2+1] * seg[i*2+2];
}

int query(int low, int high, int i, int l, int r, vector<int>& seg){
    if(l<=low && r>=high){
        return seg[i];
    }
    if(l>high || r<low || low>high){
        return 1;
    }
    int m = low +(high-low)/2;
    int x = query(low,m,i*2+1,l,r,seg);
    int y = query(m+1,high,i*2+2,l,r,seg);
    return x*y;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,k;
while(cin>>n>>k){
  vector<int> vec(n);
  vector<int> seg(n*4+6);
  fore(i,0,n){
      int x;
      cin>>x;
      if(x>0){
        vec[i] = 1;
      }
      else if(x<0)
        vec[i] = -1;
      else
        vec[i] = 0;
  }
  build(0,n-1,0,vec,seg);
  while(k--){
    char v;int a,b;
    cin>>v>>a>>b;

    if(v == 'C'){
        if(b>0) b=1;
        else if(b<0) b=-1;
        else b=0;
        act(0,n-1,0,a-1,b,seg);
    }else{
        int x = query(0,n-1,0,a-1,b-1,seg);
        if(x>0) cout<<"+";
        else if(x<0) cout<<"-";
        else cout<<"0";
    }
  }
  cout<<"\n";

}

  return 0;
}
