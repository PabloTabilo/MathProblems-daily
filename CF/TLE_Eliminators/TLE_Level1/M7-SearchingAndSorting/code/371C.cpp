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
    string recipe;
    cin >> recipe;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;

    // one cycle recipe
    ll cb = 0;
    ll cs = 0;
    ll cc = 0;
    for(auto c : recipe){
	if(c == 'B'){
	    cb++;
	}
	if(c == 'S'){
	    cs++;
	}
	if(c == 'C'){
	    cc++;
	}
    }
    function<ll(ll)> cost = [&](ll x){
	return max(0LL, cb*x - nb)*pb + max(0LL, cs*x - ns)*ps + max(0LL, cc*x - nc)*pc;
    };

    ll low = 0;
    ll hi = 1e13;
    ll ans = 0;
    while(low <= hi){
	ll mid = low + (hi - low) / 2;
	if(cost(mid) <= r){
	    ans = mid;
	    low = mid + 1;
	}else{
	    hi = mid - 1;
	}
    }
    cout << ans << '\n';
    return 0;
}

