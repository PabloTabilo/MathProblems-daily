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
    ll w, h, n;
    cin >> w >> h >> n;
    function<bool(ll)> F = [&](ll x){
	ll horizontal = x / w;
	ll vertical = x / h;
	if(horizontal >= n) return true;
	if(vertical >= n) return true;
	return horizontal >= (n + vertical - 1) / vertical;
    };

    ll lo = max(w, h);
    ll hi = max(w, h) * n;
    ll ans = -1;
    while(lo <= hi){
	ll m = lo + (hi - lo) / 2;
	//cout << "lo, m, hi = " << lo << ", " << m << ", " << hi << endl;
	if(F(m)){
	    ans = m;
	    hi = m - 1;
	}else{
	    lo = m + 1;
	}
    }
    cout << ans << '\n';
    return 0;
}

