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

void build(int low,int high,int i,const string& s, vector<pair<int,int>>& seg){
    if(low==high){
        if(s[low]=='('){
            seg[i].first=1;
        }
        else{
            seg[i].second=1;
        }
        return;
    }
    int mid=(low+high)/2;
    build(low,mid,i*2+1,s,seg);
    build(mid+1,high,i*2+2,s,seg);
    if(seg[i*2+1].first>0&&seg[i*2+2].second>0){
        if(seg[i*2+1].first>=seg[i*2+2].second){
            seg[i].first=seg[i*2+1].first-seg[i*2+2].second + seg[i*2+2].first;
            seg[i].second=seg[i*2+1].second;
        }
        else{
            seg[i].second=seg[i*2+2].second-seg[i*2+1].first + seg[i*2+1].second;
            seg[i].first=seg[i*2+2].first;
        }
    }
    else{
        seg[i].first=seg[i*2+1].first + seg[i*2+2].first;
        seg[i].second=seg[i*2+1].second+ seg[i*2+2].second;
    }
}

void sw(int low,int high, int i, int p,vector<pair<int,int>>& seg){
    if(low==high&&low==p){
        int aux=seg[i].first;
        seg[i].first=seg[i].second;
        seg[i].second=aux;
        return;
    }
    if(p<low||p>high||low>high){
        return;
    }
    int mid=(high+low)/2;
    sw(low,mid,i*2+1,p,seg);
    sw(mid+1,high,i*2+2,p,seg);

    if(seg[i*2+1].first>0&&seg[i*2+2].second>0){
        if(seg[i*2+1].first>=seg[i*2+2].second){
            seg[i].first=seg[i*2+1].first-seg[i*2+2].second + seg[i*2+2].first;
            seg[i].second=seg[i*2+1].second;
        }
        else{
            seg[i].second=seg[i*2+2].second-seg[i*2+1].first + seg[i*2+1].second;
            seg[i].first=seg[i*2+2].first;
        }
    }
    else{
        seg[i].first=seg[i*2+1].first + seg[i*2+2].first;
        seg[i].second=seg[i*2+1].second+ seg[i*2+2].second;
    }
    return;
}

void quero(vector<pair<int,int>>& seg){
    if(seg[0].first==0&&seg[0].second==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  for(int i=0; i<10; i++){
      int n;
      cin>>n;
      string s;
      cin>>s;
      vector<pair<int,int>> seg(n*4+2);
      build(0,n-1,0,s,seg);
      int t;
      cin>>t;
      cout<<"Test "<<i+1<<":"<<endl;
      while(t--){
        int m;
        cin>>m;
        if(m==0){
            quero(seg);
        }
        else{
            sw(0,n-1,0,m-1,seg);
        }
      }
  }


  return 0;
}
