#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<ll> fact(501, 1);
    for(ll i=2;i<=500;i++){
	fact[i] = ( (fact[i-1] % MOD) * (i % MOD) ) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
	ll n;
	cin >> n;
	if(n % 2 == 0){
	    ll x = n / 2;
	    //cout << "x = " << x << endl;
	    //cout << "fact[x] = " << fact[x] << endl;
	    ll ans = (fact[x] % MOD) * (fact[x] % MOD);
	    ans %= MOD;
	    cout << ans << endl;
	}else{
	    cout << 0 << endl;
	}
    }

    return 0;
}

