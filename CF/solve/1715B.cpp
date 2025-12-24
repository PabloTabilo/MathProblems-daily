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
	ll n, k, b, s;
	cin >> n >> k >> b >> s;
	ll low = k*b;
	ll high = k*b + ((k-1)>=0?k-1:0LL)*n;
	if(s < low || s > high){
	    cout << -1;
	    cout << '\n';
	    continue;
	}
	
	vector<ll> a(n,0);
	ll r = s - low;
	a[0] = low;
	ll addMe = min(r, k>0?k-1:0LL);
	a[0]+=addMe;
	r-=addMe;

	for(int i=1;i<n;i++){
	    ll take = min(r, (k>0?k-1:0LL));
	    a[i] = take;
	    r -= take;
	}

	for(ll x : a){
	    cout << x << " ";
	}
	cout << '\n';
    }
    return 0;
}

