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
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for(int i=0;i<n;i++){
	    ll addMe = 0;
	    for(int j=0;j<m;j++){
		ll v;
		cin >> v;
		addMe += v;
	    }
	    ll up = i;
	    ll down = (n-1) - i;
	    ll d = down - up;
	    cout << "addMe = " << addMe << '\n';
	    cout << "d = " << d << '\n';
	    ans += (addMe * d);
	}
	if(n == 1){
	    cout << 0 << '\n';
	    continue;
	}
	cout << ans << '\n';
    }
    return 0;
}

