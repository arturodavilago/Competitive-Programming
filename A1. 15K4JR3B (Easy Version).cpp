#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        vector<int> ans(25);
        ans[0]=1;

        for(int i=1;i<25;i++){
            ans[i]=ans[i-1]*2;
        }
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        long long a=0,b=0;
        for(int i=n-1;i>=0;i--){
            if(a<=b){
                a=a+ans[vec[i]];
            }
            else{
                b=b+ans[vec[i]];
            }
        }
        long long r=b*a;

            cout<<r<<endl;

    }
    return 0;
}
