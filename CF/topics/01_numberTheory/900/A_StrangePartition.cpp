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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        ll tot = 0;
        ll mx = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            tot += a[i];
            ll addMe = a[i] / x;
            if(a[i] % x != 0){
                addMe++;
            }
            mx += addMe;
        }

        ll mn = tot / x;
        if(tot % x != 0){
            mn++;
        }

        cout << mn << " " << mx << endl;
        
    }

    return 0;
}

