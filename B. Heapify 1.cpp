#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        int invar=0;
        for(int i=1;i<=t;i++){
            int cosa;
            cin>>cosa;
            if(i<=cosa){
                if(cosa%i!=0){
                    invar++;
                }
            }
            else{
                if(i%cosa!=0){
                    invar++;
                }
            }
        }
        if(invar==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
