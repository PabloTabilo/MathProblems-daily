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
        vector<int> a(n);
        int xorA = -1;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(xorA == -1){
                xorA = a[i];
                continue;
            }
            xorA ^= a[i];
        }
        if(n % 2 == 0){
            if(xorA == 0){
                cout << 0 << endl; 
            }else{
                cout << -1 << endl;
            }
        }else{
            cout << xorA << endl; 
        }
    }

    return 0;
}

