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
	ll n, m, k;
	cin >> n >> m >> k;
	if(k > 3){
	    cout << 0 << '\n';
	    continue;
	}
	// k = 1, 2, 3
	if(k == 1){
	    cout << 1 << '\n';
	    continue;
	}
	// k = 2, 3
	if(m == 0){
	    cout << 0 << '\n';
	    continue;
	}
	if(n == 1 && k == 3){
	    cout << 1 << '\n';
	    continue;
	}else if(n == 1 && k == 2){
	    cout << m << '\n';
	    continue;
	}
	if(m <= n){
	    if(k == 3){
		cout << 0 << '\n';
	    }else{
		cout << m << '\n';
	    }
	}else{
	    ll ans = n + max(0LL, (m / n) - 1);
	    if(k == 3){
		cout << (m - ans) << '\n';
	    }else{
		cout << ans << '\n';
	    }
	}
    }

    return 0;
}

