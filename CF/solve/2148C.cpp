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
    int t;
    cin >> t;
    while(t--){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> v(n);
	for(int i=0;i<n;i++){
	    ll a, b;
	    cin >> a >> b;
	    v[i] = {a, b};
	}
	pair<ll,ll> prev = make_pair(0,0);
	ll ans = 0;
	for(auto curr : v){
	    if(curr.second != prev.second){
		ll hi = curr.first - 1;
		ll slotsAvail = hi - prev.first;
		ans += slotsAvail;
		if(slotsAvail%2 == 0){
		    ans += 1LL;
		}
	    }else{
		ll hi = curr.first - 1;
		ll slotsAvail = hi - prev.first;
		ans += slotsAvail;
		if(slotsAvail%2 != 0){
		    ans += 1LL;
		}    
	    }
	    prev = curr;
	}
	if(prev.first < m){
	    ll hi = m - 1;
	    ll slotsAvail = hi - prev.first;
	    ans += slotsAvail+1LL;
	}
	cout << ans;
	cout << '\n';
    }

    return 0;
}

