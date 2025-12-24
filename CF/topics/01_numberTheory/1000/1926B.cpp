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
	ll a, b;
	cin >> a >> b;
	if(a == 1){
	    cout << (b*b) << '\n';
	    continue;
	}
	ll x = b;
	ll g = __gcd(a, b);
	
	if(g == 1){
	    x *= a;
	}else{
	    // factors not commun
	    ll nca = a / g;
	    ll ncb = b / g;
	    if(nca != 1 && ncb != 1){
		x *= min(nca, ncb);
	    }else if(nca == 1){
		x *= ncb;
	    }else{
		x *= nca;
	    }
	}
	cout << x << '\n';

    }

    return 0;
}

