#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;    
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        bool isPossible = false;
        for(int i=0;i<n && !isPossible;i++){
            for(int j=i+1;j<n && !isPossible;j++){
                int g = gcd(a[i], a[j]);
               if(g <= 2){
                    isPossible = true;
               } 
            }
        }
        if(isPossible){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}

