#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    string b;
    cin>>b;
    int tam=a.size();
    unordered_map<char,int> a1,a2,b1,b2;
    if(tam & 1){
        if(a != b)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl; //asd asd
        return 0;
    }
    int tam2=tam/2;
    for(int i=0;i<tam2;i++){
        a1[a[i]]++;
        b1[b[i]]++;
    }
    for(int i=tam2;i<tam;i++){
        a2[a[i]]++;
        b2[b[i]]++;
    }
    if(((a1==b1)&&(a2==b2))||((a1==b2)&&(a2==b1))){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
