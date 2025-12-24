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
	ll m = n * (n - 1) / 2;
	ll * b = new ll[m];
	for(int i=0;i<m;i++){
	    cin >> b[i];
	}
	sort(b, b + m);
	/*	
	cout << "b = ";
	for(int i=0;i<m;i++){
	    cout << b[i] << " ";
	}
	cout << endl;
	*/
	ll * a = new ll[n];
	ll j = 0;
	ll remain = n-1;
	for(int i=0;i<m;i++){
	    if(remain > 0){
		remain--;
	    }
	    if(remain == 0){
		a[j] = b[i];
		j++;
		remain = (n - 1) - j;
	    }
	}
	a[n-1] = a[n-2];

	//cout << "a = ";
	for(int i=0;i<n;i++){
	    cout << a[i] << " ";
	}
	//cout << endl;
	cout << '\n';
	delete[] a;
	delete[] b;
    }

    return 0;
}

