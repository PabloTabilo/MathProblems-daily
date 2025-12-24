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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	// >> 1, [2-n] -> max(a_2, ..., a_n) - a1 
	// >> [1,n-1], n -> a_n - min(a1, ..., a_{n-1})
	// >> [1, n] -> max(a{i} - a{i+1})
	int ans = -1;
	int mx = -1;
	for(int i=1;i<n;i++){
	    mx = max(mx, a[i]);
	}
	ans = max(ans, mx - a[0]);
	int mn = INT_MAX;
	for(int i=0;i<n-1;i++){
	    mn = min(mn, a[i]);
	}
	ans = max(ans, a[n-1] - mn);
	for(int i=0;i<n;i++){
	    ans = max(ans, a[i] - a[(i+1)%n]);
	}
	cout << ans << '\n';
    }

    return 0;
}

