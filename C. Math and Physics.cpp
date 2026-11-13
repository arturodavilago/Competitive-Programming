#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];

        }



                bool b=false;

                for(int i=0;i<n;i++){
                    if(vec[i]!=1){
                        b=true;
                    }
                }
                if(b==false){
                    cout<<"-1"<<endl;
                }
                else{
                    bool v=false;
                    for(int i=1;i<n-1;i++){
                        if(vec[i]!=1){
                            v=true;
                        }
                    }
                    if(v==false){
                        long long ans=vec[0]+vec[n-1]-1;
                        cout<<ans<<endl;
                    }
                    else{
                                    long long ans=-1;
                                    for(int i=0;i<n;i++){
                                        ans+=vec[i];
                                    }
                                    cout<<ans<<endl;
                    }
                }


    }

    return 0;
}
