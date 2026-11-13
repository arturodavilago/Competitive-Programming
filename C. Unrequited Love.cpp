#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        // CAMBIO: antes era (n/2)+1
        vector<int> vec((n+1)/2), vec2(n/2);

        if(n%2==0){
            for(int i=0;i<n/2;i++){
                // CAMBIO: eliminé estos cout de depuración
                cin>>vec[i];
                cin>>vec2[i];
            }
        }
        else{
            for(int i=0;i<(n/2)+1;i++){
                // CAMBIO: eliminé este cout de depuración
                cin>>vec[i];

                if(i!=n/2){
                    cin>>vec2[i];
                }
            }
        }

        vector<int> sum1(vec.size()-2);
        vector<int> sum2(vec2.size()-2);

        map<int,long long> mp,mp2;

        for(int i=0;i<(int)sum1.size();i++){

            // CAMBIO: antes era vec[i]+vec[i+1]+vec[i+2]
            // La fórmula del problema usa resta en el tercer elemento.
            sum1[i]=vec[i]+vec[i+1]-vec[i+2];

            mp[sum1[i]]++;
        }

        long long ans=0;

        for(int i=0;i<(int)sum2.size();i++){

            // CAMBIO: antes era vec2[i]+vec2[i+1]+vec2[i+2]
            sum2[i]=vec2[i]+vec2[i+1]-vec2[i+2];

            ans+=mp[sum2[i]];
        }

        // CAMBIO: se reemplazó el antiguo for que solamente
        // comparaba sum1[i] con sum1[i+3].
        map<int,long long> cnt1;

        for(int i=0;i<(int)sum1.size();i++){
            ans+=cnt1[sum1[i]];

            // Las tríadas de la misma paridad se solapan
            // cuando sus posiciones en este vector están
            // a distancia 1 o 2.
            if(i>=1 && sum1[i]==sum1[i-1])
                ans--;

            if(i>=2 && sum1[i]==sum1[i-2])
                ans--;

            cnt1[sum1[i]]++;
        }

        // CAMBIO: mismo conteo para sum2.
        map<int,long long> cnt2;

        for(int i=0;i<(int)sum2.size();i++){
            ans+=cnt2[sum2[i]];

            if(i>=1 && sum2[i]==sum2[i-1])
                ans--;

            if(i>=2 && sum2[i]==sum2[i-2])
                ans--;

            cnt2[sum2[i]]++;
        }

        cout<<ans<<'\n';
    }

    return 0;
}
