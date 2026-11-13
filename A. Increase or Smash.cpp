#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unordered_map <int, int> distintos;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int cualquiera;
            cin >> cualquiera;
            distintos[cualquiera] = cualquiera;
        }
        int ans=1+((distintos.size()-1)*2);
        cout << ans << endl;

    }
    return 0;
}
