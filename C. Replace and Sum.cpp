#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin>>m;
    while(m--){
        int tam;
        cin>>tam;
        int queris;
        cin>>queris;

        vector<long long> a(tam+1),b(tam+1);
        for(int i=0;i<tam;i++){
            int a1;
            cin>>a1;
            a[i]=a1;
        }
        for(int i=0;i<tam;i++){
            int b1;
            cin>>b1;
            b[i]=b1;
        }
        a[tam]=0;
        b[tam]=0;

        for(int i=tam-1;i>=0;i--){
            if(a[i]<b[i]){
                a[i]=b[i];
            }
            if(a[i]<a[i+1]){
                a[i]=a[i+1];
            }
        }

        vector<long long> x= a;
        for(int i=1;i<tam;i++){
            x[i]+=x[i-1];
        }

        while(queris--){
            int l,r,res=0;
            cin>>l>>r;
            if(l!=1){
            res=x[r-1]-x[l-2];
            }
            else{
                res=x[r-1];
            }
            cout<<res<<endl;
        }



    }
    return 0;
}
