#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,ans;
    cin>>n;
    cin>>m;

    vector <int> a(n+1);
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        a[i]=v;
    }
    a[n]=a[n-1];
    //->
    vector <int> prefixsum(n+1);
    vector <int> prefixres(n+1);
    int sum=0,res=0;
    prefixsum[0]=0;
    prefixres[0]=0;
    for(int i=1;i<n+1;i++){
        if(a[i-1]-a[i]>0){
            sum+=a[i-1]-a[i];
            prefixsum[i]=sum;
            prefixres[i]=res;
        }
        else if(a[i-1]-a[i]<0){
            res+=a[i]-a[i-1];
            prefixres[i]=res;
            prefixsum[i]=sum;
        }
        else{
            prefixres[i]=res;
            prefixsum[i]=sum;
        }
    }

    while(m--){
         int izquierda,derecha,ayuda;
        cin>>izquierda;
        cin>>derecha;
        ayuda=max(izquierda,derecha);
        if(ayuda==derecha){
            ans=prefixsum[derecha]-prefixres[izquierda];
        }
        else{
            ans=prefixsum[izquierda]-prefixres[derecha];
        }
        cout<<ans<<endl;
    }//->


    return 0;
}
