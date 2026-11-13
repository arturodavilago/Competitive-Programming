#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int sizes;
        cin >> sizes;
        string s;
        cin >> s;
        int ans=sizes;
        int i=0,j=sizes-1;
        while((s[i]=='1'&&s[j]=='0')||(s[i]=='0'&&s[j]=='1')){
                i++;
                j--;
                ans=ans-2;
        }
        if(ans<0){
            cout<<"0"<<endl;
        }
        else{
            cout <<ans<<endl;
        }


    }
    return 0;
}
