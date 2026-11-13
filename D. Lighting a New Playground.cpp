#include<bits/stdc++.h>

using namespace std;

int main(){
long long divisor,residuo,n,k;
int t;
cin>>t;
while(t--){
    cin>>n>>k;
    residuo=n%k;
    divisor=n/k;
    if(residuo>0){
        divisor++;
    }
    if(divisor<3){
        cout<<'0'<<endl;
    }
    else{
        cout<<divisor<<endl;
    }
}


return 0;
}
