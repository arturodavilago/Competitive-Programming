#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, q;
    cin >> n;
    cin >> q;
    vector <long long> a(n);
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        a[i]=p;
    }//aqui ya terminamos de leer todo vien i guess
    sort (a.begin(),a.end());
    vector <long long> prefixsum(n);
    long long constante=0;
    for(int j=0;j<n;j++){
        constante+=a[j];
        prefixsum[j]=constante;
    }//aqui ya tengo el arreglo arreglau

    for(int k=0;k<q;k++){
        long long inicio,fin,x,y,ans;
        cin >> x;
        cin >> y;
        inicio=n-x;
        fin=n-x+y-1;
        if(inicio==0){
            ans=prefixsum[fin];
        }
        else{
            ans=prefixsum[fin]-prefixsum[inicio-1];
        }
        cout<<ans<<endl;
    }

    return 0;
}
