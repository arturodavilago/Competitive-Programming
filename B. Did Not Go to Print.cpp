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
        cin.ignore();
        string s;
        cin>>s;
        vector<int> vec;
        vector<bool> vec2(n,false);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                vec.push_back(i);
            }
            else if(s[i]=='3'){
                vec2[i]=true;
            }
            else{
                if(vec.size()==0){
                    vec2[i]=true;
                }
                else{
                    vec2[vec[vec.size()-1]]=true;
                    vec.pop_back();
                }
            }

        }
        long long ac=0;
        for(int i=0;i<n;i++){
            if(vec2[i]==false){
                ac++;
            }
        }
        cout<<ac<<endl;
        for(int i=0;i<n;i++){
            if(vec2[i]==false){
                cout<<i+1<<' ';
            }
        }
        cout<<endl;

    }
    return 0;
}
