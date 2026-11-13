#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin>>m;
    while(m--){
        int tam;
        cin>>tam;
        int a1=0,a2=0;
        for(int i=0;i<tam;i++){
            int h;
            cin>>h;
            if(h==1){
                a1++;
            }
            else if(h==67){
                a2++;
            }
        }
        if(a1!=0&&a2!=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
