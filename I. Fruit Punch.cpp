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

const long long MOD = 122333221;

long long factorial(long long n) {
    long long res = 1;

    for (long long i = 2; i <= n; i++) {
        res = (res * i) % MOD;
    }

    return res;
}

long long inverso(long long a) {
    long long res = 1;
    long long exp = MOD - 2;

    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        exp /= 2;
    }

    return res;
}


int main(){
    cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n,k,dif,res,factdif,factk,multdefact,inversosu,factn;
        cin>>n>>k;
        dif=n-k;
        factn=factorial(n);
        factdif=factorial(dif);
        factk=factorial(k);
        multdefact=(factdif*factk)%MOD;
        inversosu=inverso(multdefact);
        res=(factn*inversosu)%MOD;
        cout<<res<<endl;
    }


    return 0;
}
