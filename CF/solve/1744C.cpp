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
	int n;
	char c;
	cin >> n >> c;
	unordered_map<int, vector<int>> um;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
	    um[s[i]].push_back(i);
	}
	int ans = 0;
	for(auto start : um[c]){
	    int best = INT_MAX;
	    for(auto finish : um['g']){
		int dist = finish - start;
		if(dist < 0){
		    dist += n;
		}
		best = min(best, dist);
	    }
	    ans = max(ans, best);
	}
	cout << ans;
	cout << '\n';
    }

    return 0;
}

