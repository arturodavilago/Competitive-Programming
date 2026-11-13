#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int hornos,tiempo,ans;
        cin>>hornos>>tiempo;
        vector <int> horno;
        for(int i=0;i<hornos;i++){
            int cosa;
            cin>>cosa;
            vector [i]=cosa;
        }
        horno.sort(horno.begin(),horno.end());
        int adicionales=tiempo%hornos;//con esto y lo de arriba ya leimos el vector y los datos
        int ciclos=tiempo/hornos;
        int diferencia=tiempo-(hornos-dividendo);//antes del ultimo ciclo, en el que se recoje todo

        int constante=1;
        for(int i=adicionales;i<hornos;i++){
            ans=ans+(constante*horno[i]);
            constante++;
        }//con esto ya sumamos el restante o constante
        int constante2=constante;
        for(int i=0;i<x;i++){
            ans=ans+horno[0]*constante2;
            constante2=1;
            constante++;
        }





    }
    return 0;
}
