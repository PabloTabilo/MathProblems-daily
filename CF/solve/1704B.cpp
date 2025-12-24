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
	ll n, x;
	cin >> n >> x;
	ll * low = new ll[n];
	ll * a = new ll[n];
	ll * high = new ll[n];
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    low[i] = a[i] - x;
	    high[i] = a[i] + x;
	}
	int cnt = 0;
	ll left = LLONG_MIN;
	ll right = LLONG_MIN;
	for(int i=0;i<n;i++){
	    if(left == LLONG_MIN){
		left = low[i];
		right = high[i];
		continue;
	    }
	    if(right < low[i] || left > high[i]){
		cnt++;
		left = low[i];
		right = high[i];
	    }
	    
	    left = max(left, low[i]);
	    right = min(right, high[i]);
	}
	cout << cnt;
	cout << '\n';
    }
    return 0;
}

