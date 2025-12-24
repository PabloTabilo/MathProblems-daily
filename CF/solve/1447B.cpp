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
	int n, m;
	cin >> n >> m;
	ll ** g = new ll*[n];
	for(int i=0;i<n;i++){
	    g[i] = new ll[m]();
	}
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		cin >> g[i][j];
		if((i-1)>=0 && g[i-1][j] == 0){
		    g[i][j] = abs(g[i][j]);
		}
		if((j-1)>=0 && g[i][j-1] == 0){
		    g[i][j] = abs(g[i][j]);
		}

	    }
	}
	ll sm = 0;
	ll mn = LLONG_MAX;
	ll neg = 0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		ll x = g[i][j];
		if(x < 0){
		    ++neg;
		}
		x = abs(x);
		sm += x;
		mn = min(mn, x);
	    }
	}
	if(neg%2){
	    sm -= 2LL*mn;
	}
	cout << sm << '\n';
    }

    return 0;
}

