#include <bits/stdc++.h>

using namespace std;

int main(){
    int tam;
    cin>>tam;
    vector<int> viktor(tam);
    for(int i=0;i<tam;i++){
        cin>>viktor[i];
    }
    sort(viktor(viktor.begin(),viktor.end()));
    int r=tam-1,l=0,mid;
    int query;
    cin>>query;
    while(query--){
        int var;
        cin>>var;
        while(r>l){
            mid=(r+l+1)/2;
            if(var<viktor[mid]){
                r=mid;
            }
            else if(var>viktor[mid]){
                l=mid;
            }
            else{

            }
        }
}
    return 0;
}
