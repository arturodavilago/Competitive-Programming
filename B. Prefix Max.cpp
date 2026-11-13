#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin>>m;
    while(m--){
        int n,j=0,res;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(j<a){
                j=a;
            }
        }
        res=j*n;
        cout<<res<<endl;
    }
    return 0;
}
