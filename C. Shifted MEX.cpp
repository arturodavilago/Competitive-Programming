#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n+1);
        vec[n]=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());

        int ac=1;
        int ma=1;
        for(int i=0;i<n;i++){
            if(vec[i]==vec[i+1]-1){
                ac++;
                ma=max(ma,ac);
            }
            else if(vec[i]==vec[i+1]){

            }
            else{
                ac=1;
            }
        }
        cout<<ma<<endl;

    }


    return 0;
}
