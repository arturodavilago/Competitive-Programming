#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        string s,r;
        cin>>s;
        cin>>r;
        unordered_map<char,int> ss,rr;
        for(int i=0;i<n;i++){
            ss[s[i]]++;
            rr[r[i]]++;
        }

        if(ss==rr){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
