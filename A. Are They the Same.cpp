#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> a(n),b(n);
        int acAI=0,acAP=0,acBI=0,acBP=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0){
                acAP++;
            }
            else{
                acAI++;
            }
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]%2==0){
                acBP++;
            }
            else{
                acBI++;
            }
        }
        bool ban=false;
        if(k%2==0){
            ban=true;
            //positivo, else negativo
        }
        //impares mas en a
        if(acAI>acBI){
            acAI-=acBI;
            acBI=0;
        }
        else if(acAI==acBI){
            acAI=0;
            acBI=0;
        }
        else{
            acBI-=acAI;
            acAI=0;
        }

        if(acAP>acBP){
            acAP-=acBP;
            acBP=0;
        }
        else if(acAP==acBP){
            acAP=0;
            acBP=0;
        }
        else{
            acBP-=acAP;
            acAP=0;
        }
        // ya

        if(acAI>0){
            if(ban==true){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        else if(acAP>0){
            if(ban==false){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        else{
            cout<<"YES"<<endl;
            continue;
        }



    }
    return 0;
}
