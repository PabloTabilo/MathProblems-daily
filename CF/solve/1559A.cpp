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
	vector<int> A(n);
	int mn = INT_MAX;
	int lastIdx = -1;
	for(int i=0;i<n;i++){
	    cin >> A[i];
	    if(mn > A[i]){
		lastIdx = i;
	    }
	    mn = min(mn, A[i]);
	}
	int l = lastIdx - 1;
	int r = lastIdx + 1;
	//cout << "first mn = " << mn << ", lastIdx = " << lastIdx << endl;
	while(true){
	    unordered_map<int, int> f;
	    for(int i=l;i>=0;i--){
		int curr = A[i];
		int prev = A[i+1];
		A[i] = curr & prev;
		A[i+1] = prev & curr;
	    }
	    for(int i=r;i<n;i++){
		int curr = A[i];
		int prev = A[i-1];
		A[i] = curr & prev;
		A[i-1] = prev & curr;
	    }
	    //cout << "mn = " << mn << endl;
	    //cout << "A: ";
	    for(int x: A){
		mn = min(mn, x);
		f[x]++;
		//cout << x << " ";
	    }
	    //cout << endl;
	    if(f.size() == 1){
		break;
	    }
	}
	cout << mn;
	cout << '\n';

    }

    return 0;
}

