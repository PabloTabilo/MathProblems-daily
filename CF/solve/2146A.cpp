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
	cin >> n;
	map<int, int> mp;
	for(int i=0;i<n;i++){
	    int ai;
	    cin >> ai;
	    mp[ai]++;
	}
	vector<int> f;
	for(auto p : mp){
	    f.push_back(p.second);
	}
	sort(f.begin(), f.end(), greater<int>());
	int ans = 0;
	int m = f.size();
	for(int k=1;k<=m;k++){
	    ans = max(ans, k * f[k-1]);
	}
	//cout << "ans = ";
	cout << ans; 
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

