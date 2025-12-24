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
	ll * prefix = new ll[n+1]();
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(A[i] < (i+1)){
		prefix[i+1] += 1ll;
	    }
	    prefix[i+1] += prefix[i];
	}
	/*	
	cout << "A = ";
	for(int i=0;i<n;i++){
	    cout << A[i] << " ";
	}
	cout << endl;
	
	cout << "prefix = ";
	for(int i=0;i<=n;i++){
	    cout << prefix[i] << " ";
	}
	cout << endl;
	*/
	ll cnt = 0;
	for(int i=n-1;i>=0;i--){
	    if(A[i] < (i+1) && (A[i]-1 >= 1)){
		cnt += prefix[A[i]-1];
	    }
	}
	//cout << "cnt = ";
	cout << cnt;
	//cout << endl;
	cout <<'\n';
    }
    return 0;
}

