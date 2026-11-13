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
  int t;
  cin>>t;
  while(t--){
    string s;
    lli ans=0;
    cin.ignore();
    cin>>s;
    stack<int> p,c;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            p.push(1);
           }
        else if(s[i]=='['){
            c.push(1);
        }
        else if(s[i]==')'){
            if(!(p.empty())){
                ans++;
                p.pop();
                }
        }
        else{
            if(!(c.empty())){
                ans++;
                c.pop();
                }
            }
        }

    cout<<ans<<endl;

  }

  return 0;
}
