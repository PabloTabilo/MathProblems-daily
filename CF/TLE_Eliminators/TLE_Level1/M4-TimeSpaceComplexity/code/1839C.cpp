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
	int * A = new int[n];
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	if(A[n-1] == 1){
	    cout << "NO\n";
	    continue;
	}
	int search = 1;
	vector<int> ans;
	for(int i=n-2;i>=0;i--){
	    if(A[i] == search){
		ans.push_back(i+1);
		search = 1 - search;
	    }
	}
	if(int(ans.size()) > n){
	    cout << "NO\n";
	    continue;
	}else if(int(ans.size()) < n){
	    while(int(ans.size()) < n ){
		ans.push_back(0);
	    }
	}
	reverse(ans.begin(), ans.end());
	cout << "YES\n";
	for(int i=0;i<n;i++){
	    cout << ans[i] << " ";
	}
	cout << '\n';
    }
    return 0;
}

