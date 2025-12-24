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

// mx digits: 
// 10^15 >> sqrt(10^15) = 31622777
const ll N = 31622777;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool * dp = new bool[N];
    memset(dp, true, N * sizeof(bool));
    dp[0] = dp[1] = false;
    for(ll i=2;i <= N;i++){
	if(dp[i]){
	    for(ll j = i*i; j <= N; j+=i){
		dp[j] = false;
	    }
	}
    }
    ll n;
    while(cin >> n && n != 0){
	map<ll, int> um;
	for(ll i = 2; i*i <= n; i++){
	    if(dp[i]){
		while(n % i == 0){
		    n /= i;
		    um[i]++;
		}
	    }
	}
	for(auto [x, e] : um){
	    cout << x <<"^"<<e<<" ";
	}
	if(n > 1){
	    cout << n << "^1";
	}
	cout << '\n';
    }
    return 0;
}

