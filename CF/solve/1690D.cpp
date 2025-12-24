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
	string s;
	cin >> s;
	int r=0;
	int c=0;
	int best = INT_MAX;
	for(int l=0;l<n && r<n;l++){
	    while(r < n && (r-l+1)<=k){
		if(s[r] == 'W'){
		    c++;
		}
		r++;
	    }
	    best = min(best, c);
	    if(s[l] == 'W'){
		c--;
	    }
	}
	cout << best;
	cout << '\n';
    }
    return 0;
}

