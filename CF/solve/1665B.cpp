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
	unordered_map<int, int> f;
	int mx = 0;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    f[A[i]]++;
	    mx = max(mx, f[A[i]]);
	}
	if(f.size() == 1){
	    cout << 0;
	    cout << '\n';
	    continue;
	    //cout << endl;
	}
	int ope = 0;
	while(mx < n){
	    ope += 1;
	    if(2*mx > n){
		ope += abs(n-mx);
		break;
	    }
	    ope += mx;
	    mx *= 2;
	}
	//cout << "ope = ";
	cout << ope;
	//cout << endl;
	cout << '\n';
    }

    return 0;
}

