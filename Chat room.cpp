#include <bits/stdc++.h>

using namespace std;

int main(){
    int c=0,j=0;
    string s,hello="hello";
    cin>>s;
    int n=s.size();
    for(int i=0;i<5;i++){
        while(j<n){
            if(s[j]==hello[i]){
                    c++;
                    j++;
                    break;
            }
            j++;
        }
    }
    if(c==5){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
