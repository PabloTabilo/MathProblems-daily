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
    ll lim = 1e6 + 1;
    vector<bool> dp(lim, true);
    for(ll i = 2; i*i < lim; i++){
	if(dp[i]){
	    for(ll j = 2; i*j < lim; j++){
		dp[i*j] = false;
	    }
	}
    }
    function<int(int)> nxtPrime = [&](int k){
	for(;k<lim;k++){
	    if(dp[k]){
		return k;
	    }
	}
	return -1;
    };
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll d;
	cin >> d;
	ll v2 = nxtPrime(1 + d);
	ll v3 = nxtPrime(v2 + d);
	ll a = v2 * v3;
	//cout << "v2 = " << v2 << ", v3 = " << v3 << endl; 
	cout << a << endl;
    }
    return 0;
}

