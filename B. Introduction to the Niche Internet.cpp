#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> vec(n);
        vector<long long> ans(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());

        int z=n-k;
        for(int i=0;i<k;i++){
            ans[i]=vec[z];
            z++;
        }
        z=n-k-1;
        for(int i=k;i<n;i++){
            ans[i]=vec[z];
            z--;
        }
        vector<long long> pre(n);
        pre[0]=ans[0];
        for(int i=1;i<n;i++){
            pre[i]=ans[i]+pre[i-1];
        }
        int ac=1;
        for(int i=1;i<n;i++){
            if(pre[i-1]<=ans[i]*i){
                ac++;
            }
        }


        if(ac==k){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
