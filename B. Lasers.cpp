#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y,acum=0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++){
            int v;
            cin>>v;
            if(v<y){
                acum++;
            }
        }
        for(int i=0;i<m;i++){
            int v;
            cin>>v;
            if(v<x){
                acum++;
            }
        }
        cout<<acum<<endl;
    }
    return 0;
}
