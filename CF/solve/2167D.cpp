#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

/* -- Red black tree for build a set that can get kth position -- */
/* -- not accept duplicates, its possible to implement? -- */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<ll> primes;
    ll LIM = 1e6+1;
    vector<bool> dp(LIM, true);
    for(ll i=2;i*i<LIM;i++){
	if(dp[i]){
	    primes.push_back(i);
	    for(ll j = 2; i*j < LIM; j++){
		dp[i*j] = false;
	    }
	}
    }
    int t;
    cin >> t;
    while(t--){
	ll n;
	cin >> n;
	ll * a = new ll[n];
	bool existOdd = false;
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    if(a[i] % 2 == 1){
		existOdd = true;
	    }
	}
	if(existOdd){
	    cout << 2;
	    cout << '\n';
	    continue;
	}
	ll candidate = LLONG_MAX;
	for(int i=0;i<n;i++){
	    for(auto x : primes){
		if(gcd(x, a[i]) == 1){
		    candidate = min(candidate, x);
		    break;
		}
	    }
	}
	ll mx = 1e18;
	if(candidate >= 2 && candidate <= mx){
	    cout << candidate;
	}else{
	    cout << -1;
	}
	cout << '\n';
    }

    return 0;
}

