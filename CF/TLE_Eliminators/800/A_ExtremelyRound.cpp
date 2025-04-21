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
        ll n;
        cin >> n;
        ll ans = 0;
        while(n >= 10){
            ans += 9;
            n /= 10;
        }
        ans += n;
        cout << ans << endl;
    }
    return 0;
}

