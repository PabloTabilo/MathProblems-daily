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
	unordered_map<ll, vector<int>> cnt;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    ll v = (ll)A[i] - (ll)i;
	    cnt[v].push_back(i);
	}
	ll ans = 0;
	for(int j=0;j<n;j++){
	    ll v = (ll)A[j] - (ll)j;
	    if(cnt.count(v) > 0){
		//cout << "v = " << v << ", j = " << j << endl;
		auto it = lower_bound(cnt[v].begin(), cnt[v].end(), j);
		it--;
		if(it == cnt[v].end()){
		    //cout << "it is on end: ";
		    //cout << "cnt[v] = cnt["<<v<<"] = "; for(auto x : cnt[v]) cout << x << " "; cout << endl;
		    ans += (ll)cnt[v].size();
		}else{
		    int p = it - cnt[v].begin();
		    //cout << "p = " << p << endl;
		    //cout << "cnt[v] = cnt["<<v<<"] = "; for(auto x : cnt[v]) cout << x << " "; cout << endl;
		    ans += (ll)(p+1);
		}
	    }
	}
	//cout << "ans = ";
	cout << ans;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

