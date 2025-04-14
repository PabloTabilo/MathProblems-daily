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
        ll x, y;
        cin >> x >> y;
        ll diff = x - y;
        if(diff == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}

