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
    vector<int> A(n);
    for(int i=0;i<n;i++){
	cin >> A[i];
    }
    sort(A.begin(), A.end());
    auto bs = [&](int v, bool imRight){
	int ans = -1;
	int l = 0;
	int r = n;
	while(l < r){
	    int mid = l + (r - l) / 2;
	    //cout << "l, mid, r = " << l << "," << mid << "," << r << '\n';
	    if(imRight && A[mid] <= v){
		ans = mid;
		l = mid + 1;
	    }else if(!imRight && A[mid] < v){
		ans = mid;
		l = mid + 1;
	    }
	    else{
		r = mid;
	    }
	}
	return ans;
    };
    //cout << "A: "; for(auto x : A) cout << x << " ";cout << '\n';
    int q;
    cin >> q;
    vector<int> ans;
    while(q--){
	int v1, v2;
	cin >> v1 >> v2;
	//cout << "v1 = " << v1 << '\n';
	int idx1 = bs(v1, false); // check instances less only
	//cout << "idx1 = " << idx1 << '\n';
	//cout << "v2 = " << v2 << '\n';
	int idx2 = bs(v2, true); // extend to more far away
	//cout << "idx2 = " << idx2 << '\n';
	int diff = idx2 - idx1;
	ans.push_back(diff);
    }
    //cout << "ans: "; 
    for(auto x : ans) cout << x << " "; cout << '\n';

    return 0;
}

