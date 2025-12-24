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
	ll n, k;
	cin >> n >> k;
	ll sz = n*k;
	ll * A = new ll[sz];
	for(int i=0;i<sz;i++){
	    cin >> A[i];
	}
	ll groupsSz = sz / k;
	ll medianPosition = groupsSz / 2;
	if(groupsSz % 2 == 0){
	    medianPosition--;
	}
	//cout << "The medianPosition = " << medianPosition << endl;
	int l = 0;
	int r = sz-1;
	ll ans = 0;
	while(l <= r){
	    ll cnt = groupsSz-1;
	    while(cnt > medianPosition){
		cnt--;
		r--;
	    }
	    ll median = A[r];
	    //cout << "r = " << r << endl;
	    //cout << "group has this as median = " << median << endl;
	    ans += median;
	    cnt--;
	    r--;
	    while(cnt >= 0){
		l++;
		cnt--;
	    }
	    //cout << "end with this l = "<<l<<endl;
	}
	cout << ans;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

