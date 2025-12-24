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
	int n, r, b;
	cin >> n >> r >> b;
	int best = INT_MAX;
	int G = -1;
	int EXTRA = -1;
	for(int g=1;;g++){
	    int totR = g*b;
	    int extra = r - totR;
	    int mx = max(g, extra);
	    //cout << "g = " << g << endl;
	    //cout << "totR = " << totR << endl;
	    //cout << "extra = " << extra << endl;
	    //cout << "mx = " << mx << endl;
	    if(best > mx){
		best = mx;
		G = g;
		EXTRA = extra;
	    }
	    if(extra < 0){
		break;
	    }
	}
	string t = "B";
	string ans = "";
	for(int i=0;i<G;i++){
	    t += 'R';
	}
	if(EXTRA > 0){
	    for(int i=0;i<EXTRA;i++){
		ans += 'R';
	    }
	    for(int i=0;i<b;i++){
		ans += t;
	    }
	}else{
	    for(int i=0;i<(b+EXTRA);i++){
		ans += t;
	    }
	    t.pop_back();
	    for(int i=0;i<(-EXTRA);i++){
		ans += t;
	    }
	}
	cout << ans;
	cout << '\n';

    }
    return 0;
}

