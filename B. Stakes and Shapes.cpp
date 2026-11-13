#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,s,p;
        cin>>r>>s>>p;

        int m=max(r,s);
        m=max(m,p);

        int acum=r+s+p;

        if(m==r){
            for(int i=0;i<acum;i++){
                cout<<"P";
            }
            cout<<endl;
        }
        else if(m==s){
            for(int i=0;i<acum;i++){
                cout<<"R";
            }
            cout<<endl;
        }
        else{
            for(int i=0;i<acum;i++){
                cout<<"S";
            }
            cout<<endl;
        }

    }

    return 0;
}
