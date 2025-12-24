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
	ll n, q;
	cin >> n >> q;
	ll * A = new ll[n];
	ll * prefix = new ll[n];
	ll * mxV = new ll[n];
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(i == 0){
		prefix[i] = A[i];
		mxV[i] = A[i];
	    }else{
		prefix[i] = A[i] + prefix[i-1];
		mxV[i] = max(mxV[i-1], A[i]);
	    }
	}
	
	/*
	cout << "prefix: ";
	for(int i=0;i<n;i++){
	    cout << prefix[i] << " ";
	}
	cout << endl;

	cout << "mxV: ";
	for(int i=0;i<n;i++){
	    cout << mxV[i] << " ";
	}
	cout << endl;
	*/
	for(int i=0;i<q;i++){
	    ll k;
	    cin >> k;
	    auto it = upper_bound(mxV, mxV+n, k);
	    if(it != mxV + n){
		int idx = it - mxV;
		if(idx == 0 && k < prefix[0]){
		    cout << 0 << " ";
		    continue;
		}
		idx--;
		//cout << "for k = " << k << ", upper_bound = " << idx << endl;
		cout << prefix[idx] << " ";
	    }else{
		//cout << "k is larger than all values on mxV" << endl;
		cout << prefix[n-1] << " ";
	    }
	}
	cout << '\n';
    }

    return 0;
}

