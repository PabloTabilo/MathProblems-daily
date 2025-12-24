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
    ll N, D;
    cin >> N >> D;
    ll * P = new ll[N];
    for(int i=0;i<N;i++){
	cin >> P[i];
    }
    sort(P, P + N);
    int l = 0;
    int r = N-1;
    ll ans = 0;
    while(l <= r){
	ll best = P[r];
	ll cnt = 1;
	ll tot = best;
	for(;l<r && tot <= D;l++){
	    cnt++;
	    tot = best * cnt;
	}
	if(tot > D){
	    ans++;
	}
	r--;
    }
    cout << ans;
    cout << '\n';
    return 0;
}

