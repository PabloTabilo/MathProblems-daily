#include <iostream>
#include <bits/stdc++.h>
using namespace std;


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
	bool isPossible = false;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(i > 0 && A[i-1] <= A[i]){
		isPossible = true;
	    }
	}
	if(isPossible){
	    cout << "YES\n";
	}else{
	    cout << "NO\n";
	}
    }

    return 0;
}

