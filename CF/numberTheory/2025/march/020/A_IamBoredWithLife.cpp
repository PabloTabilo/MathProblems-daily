#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a, b;
    cin >> a >> b;
    ll mn = min(a, b);
    ll ans = 1;
    for(ll i = 1; i <= mn; i++){
	ans *= i;
    }
    cout << ans << endl; 
    return 0;
}

