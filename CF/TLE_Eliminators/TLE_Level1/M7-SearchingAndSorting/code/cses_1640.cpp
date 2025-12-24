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
    int n, x;
    cin >> n >> x;
    unordered_map<ll, int> hm;
    int idx1 = -1;
    int idx2 = -1;
    for(int i=0;i<n;i++){
	ll a;
	cin >> a;
	if(a >= x){
	    continue;
	}
	ll r = x - a;
	if(hm.count(r) > 0){
	    idx2 = i;
	    idx1 = hm[r];
	}
	hm[a] = i;
    }
    if(idx1 == -1){
	cout << "IMPOSSIBLE\n";
	return 0;
    }
    idx1++;
    idx2++;
    cout << idx1 << " " << idx2 << '\n';
    return 0;
}

