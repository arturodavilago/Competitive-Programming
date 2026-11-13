#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,wub="WUB",ans;
    cin>>s;
    s+="))";
    bool f=true;
    int tamanio=s.size();
    for(int i=0;i<tamanio-2;i++){
        string ayuda = s.substr(i,3);
        if(ayuda=="WUB"){
            if(!f){
                ans=ans+' ';
            }
            i=i+2;
            f = true;
        }
        else{
            ans=ans+s[i];
            f = false;
        }
    }
 /*   if(ans[ans.size()-1]==' '){
        ans.pop_back();
    }*/
    cout<<ans<<endl;
    return 0;
}
