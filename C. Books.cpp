#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,t;
    cin>>n;
    cin>>t;
    vector <long long> a(n);

    for(long long i=0;i<n;i++){
        cin>>a[i];
    }

    long long r=0,l=0,acumulador=0,maximun=0,cantidad=0;
    while(r<n){

        if(acumulador<=t){
            acumulador+=a[r];
            if(acumulador>t){
                acumulador-=a[l];
                l++;
            }
            r++;
        }
        else if(acumulador>t){
                acumulador-=a[l];
                l++;
            }

        cantidad=r-l;
        maximun= max(maximun,cantidad);
    }
            cout<<maximun<<endl;
    return 0;
}
