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
	int l, r;
	cin >> l >> r;

	int mask = 1;
	int bit = 0;
	while(mask <= r){
	    mask <<= 1;
	    bit++;
	}
	mask--;
	int sz = r + 1;
	vector<int> a(sz, 0);
	int R = r;
	while(R>=0){
	    int k = 0;
	    while( ((1<<k)-1) < R){
		k++;
	    }
	    int M = (1 << k) - 1;
	    int L = max(0, M - R);
	    for(;R >= L;R--){
		a[R] = M - R;
	    }
	}
	ll sc = 0;
	for(ll i = 0; i < sz; i++){
	    ll ai = (ll)a[i];
	    ll v = ai | i;
	    sc += v;
	}
	cout << sc;
	//cout << endl;
	//cout << "a: ";
	cout << '\n';
	for(auto x : a){
	    cout << x << " ";
	}
	//cout << endl;
	cout << '\n';
    }
    return 0;
}

