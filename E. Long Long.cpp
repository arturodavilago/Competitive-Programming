#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int tam;
        cin>>tam;
        vector <long long> viktor(tam);
        for(int i=0;i<tam;i++){
            int temp;
            cin>>temp;
            viktor[i]=temp;
        }

        long long k=1,i=0,j=tam-1,cont=0;
        while(i<=j){
        if(k==1){
            if(viktor[i]>=0){
                i++;
            }
            else if(viktor[j]>=0){
                j--;
            }
            else if(viktor[j]<0&&viktor[i]<0){
                k++;
                cont++;
            }
        }
        else{
            if(viktor[i]<=0){
                i++;
            }
            else if(viktor[j]<=0){
                j--;
            }
            else if(viktor[j]>0&&viktor[i]>0){
                k--;
                cont++;
            }
        }
        }

        long long acum=0;
        for(int i=0;i<tam;i++){

        if(viktor[i]<0){
            acum+=viktor[i]*-1;
            }

        else{
            acum+=viktor[i];
        }

        }

        cout<<acum<<" "<<cont<<endl;
    }
    return 0;
}
