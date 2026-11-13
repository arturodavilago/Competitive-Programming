#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,r;
        cin>>x>>y>>r;
        y+=r;
        cout<<x<<' '<<y<<endl;
    }

    return 0;
}
