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
	ll n;
	cin >> n;
	bool notPossible = true;
	while(notPossible){
	    //cout << "n = " << n << endl;
	    string s = to_string(n);
	    //cout << "s = " << s << endl;
	    vector<bool> exist(10, false);
	    for(char c : s){
		exist[c-'0'] = true;
	    }
	    //cout << "exist: "; for(auto x : exist) cout << x << " "; cout << endl;
	    notPossible = false;
	    for(int i=1;i<10;i++){
		//cout << "i = " << i << endl;
		if(exist[i] && (n%i!=0)){
		    notPossible = true;
		    break;
		}
	    }
	    //cout << "notPossible = " << notPossible << endl;
	    if(notPossible){
		n++;
	    }
	}
	cout << n << '\n';
    }
    return 0;
}

