#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> mp;
        mp[-1]=0;mp[0]=0;
        while(n--){
            int a;
            cin>>a;
            mp[a]++;
        }
        int ans=((mp[-1]%2)*2)+mp[0];
        cout<<ans<<endl;
    }
    return 0;
}
