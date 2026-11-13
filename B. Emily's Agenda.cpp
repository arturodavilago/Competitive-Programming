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
#define debx(...) (_VA_ARGS_)
#ifdef LOCAL
#include "debug.h"
#endif
using ld = long double;
using lli = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  int n,tac=0,ans=0;

  cin>>n;
  vector <pair<int,int>> vec(n);
  cin.ignore();

            //leer
          for(int i=0;i<n;i++){
            string a;
            getline(cin,a);
            int v=stoi(a.substr(0,2));
            int v1=stoi(a.substr(3,2));
            int b=stoi(a.substr(6,2));
            int b1=stoi(a.substr(9,2));

            vec[i].second=v*60+v1;
            vec[i].first=b*60+b1;
            if(vec[i].second>=vec[i].first){
                vec[i].first=vec[i].first + 1440;
            }
          }

    sort(all(vec));
    //sort(vec.begin(), vec.end()));

    for(int j=0;j<n;j++){
        if(tac>=1440){
            cout<<ans<<endl;
            return 0;
        }

        if(vec[j].second>=tac){
            ans++;
            tac=vec[j].first;
        }
    }
    cout<<ans<<endl;



  return 0;
}
