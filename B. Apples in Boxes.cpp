#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int vg=1;
        long long maximun=0, minimun=INT_MAX, suma=0;
        for(int i=0;i<n;i++){
            long long v;
            cin >> v;
            suma+=v;
            if(maximun==v){
                vg++;
            }
            if(maximun<v){
                vg=1;
            }
            maximun = max(maximun, v);
            minimun = min(minimun, v);

        }

        if(vg==1){
            long long dif=(maximun-1)-minimun;
            if(dif<=k&&suma%2==1){
                cout <<"Tom"<< endl;
            }
            else{
                cout<<"Jerry"<<endl;
            }
        }
        else{
               long long dif=(maximun)-minimun;
            if(dif<=k&&suma%2==1){
                cout <<"Tom"<< endl;
            }
            else{
                cout<<"Jerry"<<endl;
            }
        }




    }
    return 0;
}
