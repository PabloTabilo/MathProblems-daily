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
        vector<ll>a(n);
        ll times = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            while( (a[i] % 2) == 0){
                a[i] /= 2;
                times++;
            } 
        }
        ll mx = *max_element(a.begin(), a.end());
        //cout << "a - post: "; for(auto x : a) cout << x << " "; cout << endl;
        ll ans = accumulate(a.begin(), a.end(), 0LL);
        ans -= mx;
        ans += (mx * (ll)pow(2LL, times));
        cout << ans << endl;
    }
    return 0;
}

