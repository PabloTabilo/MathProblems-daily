#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        int ans = 0;
        for(int i=0;i<10;i++){
            cin >> s;
            for(int j=0;j<10;j++){
                if(s[j] == 'X'){
                    //cout << endl; cout << "i, j = " << i << ", " << j << endl; 
                    int yp = min(i+1, 10 - i);
                    int xp = min(j+1, 10 - j);
                    //cout << "yp, xp = " << yp << ", " << xp << endl;
                    ans += min(yp, xp);
                    //cout << "ans = " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

