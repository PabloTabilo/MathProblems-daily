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
	int n, k;
	cin >> n >> k;
	int * A = new int[n];
	ll cost = LLONG_MAX;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(A[i] % k != 0){
		int r = A[i] % k;
		ll dist = (ll)k - (ll)r;
		cost = min(cost, dist);
	    }else{
		cost = 0;
	    }
	}
	if(k == 4){
	    ll cnt0s = 0;
	    ll cnt1s = 0;
	    for(int i=0;i<n;i++){
		if(A[i]%2 == 0){
		    cnt0s++;
		}else if(A[i]%4 == 1){
		    cnt1s++;
		}
	    }
	    //cout << "cnt0s = " << cnt0s << ", cnt1s = " << cnt1s << endl;
	    if(cnt0s >= 2LL){
		cost = 0LL;
	    }
	    if(cnt0s == 0 && cnt1s >= 2LL){
		cost = min(cost, 2LL);
	    }
	    if(cnt0s > 0 && (cnt0s + cnt1s) >= 2LL){
		cost = min(cost, 1LL);
	    }
	}
	//cout << "cost = ";
	cout << cost;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

