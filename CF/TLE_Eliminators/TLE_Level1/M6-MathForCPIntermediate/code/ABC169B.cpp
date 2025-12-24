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
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
	cin >> A[i];
    }

    sort(A.begin(), A.end());

    ll lim = 1e18;
    ll times = -1;
    ll ans = 1;
    bool isPossible = true;
    for(int i=0;i<n;i++){
	ll v = A[i];
	times = lim / ans;
	//cout << "ans = " << ans << '\n';
	//cout << "times = " << times << '\n';
	//cout << "v = " << v << '\n';
	if(v > times){
	    //cout << "ENTER\n";
	    isPossible = false;
	}
	if(isPossible){
	    ans *= v;
	}
	if(ans == 0){
	    break;
	}
    }

    if(isPossible){
	cout << ans << '\n';
    }else{
	cout << -1 << '\n';
    }

    return 0;
}

