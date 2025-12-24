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
	int x, k;
	cin >> x >> k;
	bool isPossible = true;
	for(int i=2; i*i <= x; i++){
	    if(x % i == 0){
		isPossible = false;
		break;
	    }
	}
	if(!isPossible){
	    cout << "NO\n";
	    continue;
	}
	if(k > 1){
	    if(x == 1){
		ll c = 0;
		while(k--){
		    c *= 10;
		    c += 1;
		}
		//cout << "c = " << c << '\n';
		for(ll i=2;i*i<=c;i++){
		    if(c % i == 0){
			isPossible = false;
			break;
		    }
		}
		if(!isPossible){
		    cout << "NO\n";
		    continue;
		}
		cout << "YES\n";
		continue;
	    }
	    cout << "NO\n";
	    continue;
	}
	if(x == 1){
	    cout << "NO\n";
	    continue;
	}
	cout << "YES\n";
    }

    return 0;
}

