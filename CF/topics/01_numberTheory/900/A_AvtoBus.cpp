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
        // n = 4 * x + 6 * y
        cin >> n;    
        if(n < 4 || n % 2 != 0){
            cout << -1 << endl;
            continue;
        }
        ll y = n / 6LL;
        ll x = 0;
        if(n % (6LL) != 0){
            y--;
            y = max(y, 0LL);
            x = (n - 6LL*y) / 4LL;
        }
        ll mn = y + x;
        
        mn = max(mn, 1LL);

        x = n / 4LL;
        y = 0;
        if(n % (4LL) != 0){
            x--;
            x = max(x, 0LL);
            y = (n - 4LL*x) / 6LL;
        }
        ll mx = x + y;
        mx = max(mx, 1LL);
        
        cout << mn << " " << mx << endl;
    }
    return 0;
}

