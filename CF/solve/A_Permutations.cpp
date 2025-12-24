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
        int n, a, b;
        cin >> n >> a >> b;
        if(n == 1){
            cout << "Yes" << endl;
            continue;
        }
        if(a == b && a == n){
            cout << "Yes" << endl;
            continue;
        }
        int fix = a + b;
        if( (n - fix) >= 2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}

