#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
	vector<ll> e, o;
	for(int i=0;i<n;i++){
	    ll v;
	    cin >> v;
	    if(v % 2 == 0){
		e.push_back(v);
	    }else{
		o.push_back(v);
	    }
	}
	ll se = 0;
	ll so = 0;
	sort(e.begin(), e.end());
	sort(o.begin(), o.end());
	bool A = true;
	int i = e.size() - 1;
	int j = o.size() - 1;
	while(i>=0 || j >= 0){
	    if(A){
		if(i >= 0){
		    if((i>=0 && j>=0 && e[i] >= o[j]) || (i >= 0 && j < 0)){
			se += e[i];
			i--;
		    }else{
			j--;
		    }
		}else{
		    j--;
		}
		A = false;
	    }else{
		if(j >= 0){
		    if( (j >= 0 && i < 0) || (i >= 0 && j >= 0 && o[j] >= e[i]) ){
			so += o[j];
			j--;
		    }else{
			i--;
		    }
		}else{
		    i--;
		}
		A = true;
	    }
	}

	if(se > so){
	    cout << "Alice\n";
	}else if(se < so){
	    cout << "Bob\n";
	}else{
	    cout << "Tie\n";
	}
    }

    return 0;
}

