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
	vector<vector<ll>> ans(n, vector<ll>(2, 0));
	for(int i=0;i<n;i++){
	    int m;
	    cin >> m;
	    vector<ll>t(m, 0);
	    for(int j=0;j<m;j++){
		cin >> t[j];
	    }
	    sort(t.begin(), t.end());
	    ans[i][0] = t[0];
	    ans[i][1] = t[1];
	}
	ll mn = LLONG_MAX;
	ll mn_of_mx = LLONG_MAX;
	for(int i=0;i<n;i++){
	    mn = min(mn, ans[i][0]);
	    mn_of_mx = min(mn_of_mx, ans[i][1]);
	}
	//cout << "mn = " << mn << endl;
	//cout << "mn_of_mx = " << mn_of_mx << endl;
	ll sc = mn;
	for(int i=0;i<n;i++){
	    //cout << "i: " << i << " >> {" << ans[i][0] << "," << ans[i][1] << "}" << endl;
	    if(ans[i][1] != mn_of_mx){
		sc += ans[i][1];
	    }else{
		mn_of_mx = -1;
	    }
	}
	//cout << "sc = ";
	cout << sc;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

