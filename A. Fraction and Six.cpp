#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cin.ignore();
        string s,c;
        cin>>s>>c;
        vector<char> s1(n),c1(m);
        for(int i=0;i<n;i++){
            s1[i]=s[i];
        }
        for(int i=0;i<m;i++){
            c1[i]=c[i];
        }

        if(n-3!=m){
            cout<<"NO"<<endl;
            continue;
        }
        bool b;
        for(int i=0;i<m;i++){
                b=false;
            for(int j=0;j<n;j++){
                if(s1[j]==c1[i]){
                    s1.erase(s1.begin()+j);
                    b=true;
                    break;
                }
            }
            if(b==false){
                cout<<"NO"<<endl;
                break;
            }

        }


    }

    return 0;
}
