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
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	ll cnt = 0;
	ll l = 0;
	ll r = 0;
	vector<ll> w;
	while(l < n && r < n){
	    while(l < n && a[l] > q){
		l++;
	    }
	    r = l;
	    while(r < n && a[r] <= q){
		r++;
	    }
	    ll width = r - l;
	    if(width >= k){
		w.push_back(width);
	    }
	    //cout << "l, r = " << l << ", " << r << endl;
	    //cout << "width = " << width << endl;
	    //cout << "-----------------" << endl;
	    l = r;
	    cnt++;
	}
	ll ans = 0;
	//cout << "widths: ";
	for(auto x : w){
	    //cout << x << " ";
	    ll s = x - k + 1;
	    ans += (s * (s+1))/2;
	}
	//cout << endl;
	//cout << "ans = "; 
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

