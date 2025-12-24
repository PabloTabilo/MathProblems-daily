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
	ll x0, n;
	cin >> x0 >> n;
	if(n == 0){
	    cout << x0 << '\n';
	    continue;
	}
	ll ans = x0;
	x0 = abs(x0);
	ll mxGroups = (n-1)/4;
	if(x0 % 2 == 1){
	    ans += 4*mxGroups;
	}else{
	    ans -= 4*mxGroups;
	}
	ll remainder = (n-1)%4;
	if(remainder > 0){
	    ll f1 = 1 + mxGroups*4 + 1;
	    ll f2 = 1 + mxGroups*4 + 2;
	    ll f3 = 1 + mxGroups*4 + 3;
	    if(x0 % 2 == 1){
		f1*=-1;
		f2*=-1;
	    }else{
		f3*=-1;
	    }
	    if(remainder == 1){
		ans += f1;
	    }else if(remainder == 2){
		ans += (f1+f2);
	    }else{
		ans += (f1+f2+f3);
	    }
	}
	if(x0 % 2 == 1){
	    ans++;
	}else{
	    ans--;
	}
	//cout << "ans: ";
	cout << ans;
	cout << '\n';
	//cout << endl;
    }

    return 0;
}

