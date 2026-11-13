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

vector<lli> lazy(4*200005, 0);
vector<lli> seg(4*200005);
vector<int> vec(200005);

void build(int i, int low, int high){
    if(low == high){
        seg[i] = vec[low];
        return;
    }
    int m = (high+low)/2;
    build(2*i+1, low, m);
    build(2*i+2, m+1, high);
    seg[i] = min(seg[2*i+1], seg[2*i+2]);
}

lli ans(int i, int low, int high, int l, int r){
    if(lazy[i]!=0){
        seg[i]+=lazy[i];
        if(low != high){
        lazy[i*2+1]+=lazy[i];
        lazy[i*2+2]+=lazy[i];

        }
        lazy[i]=0;
    }
    if(r<low||l>high||low>high){
        return LLONG_MAX;
    }
    if(low>=l&&high<=r){
        return seg[i];
    }

    int mid=(high+low)>>1;
    lli x=ans(i*2+1,low,mid,l,r);
    lli y=ans(i*2+2,mid+1,high,l,r);
    seg[i] = min(seg[i*2+1],seg[i*2+2]);
    return min(x,y);
}

void inc(int i, int low, int high, int l, int r, int val){
    if(lazy[i] != 0){
        seg[i] += lazy[i];
        if(low != high){
        lazy[i*2+1]+=lazy[i];
        lazy[i*2+2]+=lazy[i];

        }
        lazy[i] = 0;
    }
    if(r < low || high < l||low>high){
        return;
    }
    if(low >= l && high <= r){
        seg[i] += val;
        if(low!=high){
        lazy[2*i+1] += val;
        lazy[2*i+2] += val;
        }
        return;
    }


    int m = (high+low)>>1;
    inc(2*i+1, low, m, l, r, val);
    inc(2*i+2, m+1, high, l, r, val);
    seg[i] = min(seg[2*i+1], seg[2*i+2]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n;
  cin>>n;
  fore(i,0,n){
      cin>>vec[i];
  }
  build(0,0,n-1);

  int t;
  cin>>t;
  cin.ignore();
  while(t--){
        int a,b,c;
        string s;
        getline(cin,s);
        stringstream ss(s);
        ss>>a>>b;
        if(ss>>c){
            if(a > b){
            inc(0,0,n-1,a,n-1,c);
            inc(0,0,n-1,0,b,c);
            continue;
        }
        inc(0,0,n-1,a,b,c);
        }
        else{
        if(a > b){
                cout<<min(ans(0,0,n-1,a,n-1),ans(0,0,n-1,0,b))<<endl;
                continue;
            }
            cout<<ans(0,0,n-1,a,b)<<endl;
            continue;
        }

  }

  return 0;
}
