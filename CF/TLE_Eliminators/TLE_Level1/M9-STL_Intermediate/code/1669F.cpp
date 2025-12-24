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
	ll * w = new ll[n];
	for(int i=0;i<n;i++){
	    cin >> w[i];
	}
	int l = -1;
	int r = n;
	ll wl = 0;
	ll wr = 0;
	ll ans = 0;
	ll cnt = 0;
	while(l < r){
	    //cout << "l = " << l << ", r = " << r;
	    //cout << ", wl = " << wl << ", wr = " << wr << endl;
	    if(l>=0 && r < n && wl < wr){
		l++;
		wl += w[l];
		cnt++;
	    }else if(l>=0 && r < n && wl > wr){
		r--;
		wr += w[r];
		cnt++;
	    }else{
		l++;
		r--;
		if(l >= r){
		    break;
		}
		wl += w[l];
		wr += w[r];
		cnt+=2;
	    }
	    if(wl == wr){
		//cout << "MUST CNT: cnt = " << cnt << endl;
		ans = max(ans, cnt);
	    }
	}
	//cout << "final: ";cout << "wl = " << wl << ", wr = " << wr << endl;
	//cout << "ans = ";
	cout << ans;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

