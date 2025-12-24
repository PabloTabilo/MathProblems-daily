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
    int * A = new int[n];
    for(int i=0;i<n;i++){
	cin >> A[i];
    }
    int l = 0;
    set<int> last;
    int ans = 0;
    for(int r=0;r<n;r++){
	if(last.count(A[r]) > 0){
	    while(A[l] != A[r]){
		last.erase(A[l]);
		l++;
	    }
	    last.erase(A[l]);
	    l++;
	}
	//cout << "l, r = " << l << ", " << r << '\n';
	last.insert(A[r]);
	//cout << "last: "; for(auto v : last) cout << "{"<<v<<"} ";cout << '\n';
	ans = max(ans, int(last.size()));
    }
    cout << ans << '\n';
    return 0;
}

