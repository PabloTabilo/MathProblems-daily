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
	ll * A = new ll[n];
	ll cnt0s = 0;
	ll cnt1s = 0;
	ll sume = 0LL;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(A[i] == 1){
		cnt1s++;
	    }else if(A[i] == 0){
		cnt0s++;
	    }
	    sume += A[i];
	}
	if(cnt1s == 0){
	    cout << 0;
	    cout << '\n';
	    continue;
	}
	ll waysZeros = 1LL << cnt0s;
	ll ans = cnt1s * waysZeros;
	cout << ans;
	cout << '\n';
    }

    return 0;
}

