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
	int * b = new int[n];
	set<int> isDuplicate;
	bool isPossible = false;
	for(int i=0;i<n;i++){
	    cin >> b[i];
	    if(isDuplicate.find(b[i]) != isDuplicate.end()){
		isPossible = true;
	    }
	    isDuplicate.insert(b[i]);
	}
	if(isPossible){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }
    return 0;
}

