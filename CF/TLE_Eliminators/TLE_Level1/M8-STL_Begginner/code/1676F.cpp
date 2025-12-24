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
	map<int, int> f;
	for(int i=0;i<n;i++){
	    int val;
	    cin >> val;
	    f[val]++;
	}	
	vector<int> vec;
	for(auto p : f){
	    vec.push_back(p.first);
	    //cout << "{"<<p.first<<","<<p.second<<"} ";
	}
	// cout << endl;
	int m = vec.size();
	int l = 0;
	int ans = 0;
	int bestL = -1;
	int bestR = -1;
	int sz = -1;
	for(int r=0;r<m;r++){
	    int freq = f[vec[r]];
	    if(freq < k){
		l = r + 1;
	    }else{
		// must be consecutive
		if(l == r || (r-1) >= 0 && (abs(vec[r] - vec[r-1]) <= 1) ) {
		    sz = r - l + 1;
		    if(sz > ans){
			bestL = vec[l];
			bestR = vec[r];
			ans = sz;
		    }
		}else{
		    l = r;
		}
	    }
	    /*
	    cout << "l = " << l << ", r = " << r << endl;
	    cout << "vec[r] = " << vec[r] << endl;
	    cout << "f[vec[r]] = " << f[vec[r]] << endl;
	    cout << "ans = " << ans << endl;
	    cout << "sz = " << sz << endl;
	*/
	}
	// cout << "ans = " << ans << endl;
	// cout << "bestL bestR = ";
	if(bestL == -1){
	    cout << -1 << '\n';
	    continue;
	}
	cout << bestL << " " << bestR << '\n';
	// cout << endl;
    }
    return 0;
}

