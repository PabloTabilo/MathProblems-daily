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
	set<int> s;
	vector<int> A;
	for(int i=0;i<n;i++){
	    int v;
	    cin >> v;
	    if(v % 2 == 0){
		if(s.find(v) == s.end()){
		    A.push_back(v);
		    s.insert(v);
		}
	    }
	}
	sort(A.begin(), A.end());
	// 6 8 12 6 3 12
	// 6 8 6 6 3 6
	// 3 8 3 3 3 3
	// 3 1 3 3 3 3
	// ope = 1 + 1 + 3 = 5
	int ope = 0;
	int m = A.size();
	for(int i = m-1; i>=0;i--){
	    int candidate = A[i];
	    while(candidate % 2 == 0){
		candidate /= 2;
		ope++;
		if(s.find(candidate) != s.end()){
		    break;
		}
	    }
	}
	cout << ope << '\n';
    }
    return 0;
}

