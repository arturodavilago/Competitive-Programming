#include <bits/stdc++.h>

using namespace std;

long long MOD=998244353;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            s.insert(vec[i]);
        }
        sort(vec.begin(),vec.end());
        long long r=0;
        r=r+n;
        vector<long long> ac(n+1);
        ac[n]=0;
        for(int i=n-1;i>=0;i--){
            r+=(n-1-i);
            r=r%MOD;
            ac[i]=ac[i+1]+n-1-i;
        }
        cout<<"res 1: "<<r<<endl;
        for(int i=0;i<n-2;i++){
            if(s.count(vec[i]+1)){
                cout<<"iter"<<i<<endl;
                r+=ac[i+1];
                r=r%MOD;
            }
        }
        cout<<"res "<<r<<endl;

    }
    return 0;
}
