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
    int n, m;
    cin >> n >> m;
    multiset<int> A;
    for(int i=0;i<n;i++){
	int ai;
	cin >> ai;
	A.insert(ai);
    }
    A.insert(-1);
    //cout << "A : "; for(auto x : A) cout << x << " "; cout << endl;

    for(int i=0;i<m;i++){
	int q;
	cin >> q;
	auto it = A.lower_bound(q);
	if(it == A.end()){
	    it--;
	}
	//cout << "*(it) = " << (*it) << endl;
	if(*(it) == -1){
	    cout << -1 << '\n';
	    continue;
	}
	if(*(it) <= q){
	    cout << *(it) << '\n';
	    A.erase(it);
	}else{
	    it--;
	    if(*(it) == -1){
		cout << -1 << '\n';
		continue;
	    }
	    cout << *(it) << '\n';
	    A.erase(it);
	}
	//cout << "A : "; for(auto x : A) cout << x << " "; cout << endl;
    }
    return 0;
}

