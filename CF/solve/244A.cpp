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
    int n, k;
    cin >> n >> k;
    set<int> a;
    int * A = new int[k];
    for(int i=0;i<k;i++){
	cin >> A[i];
	a.insert(A[i]);
    }
    int i = 1;
    for(int ki = 0; ki < k; ki++){
	int cnt = 1;
	cout << A[ki] << " ";
	for(;i<=(n*k);i++){
	    if(cnt == n){
		break;
	    }
	    if(a.find(i) == a.end()){
		cout << i << " ";
		cnt++;
	    }
	}
	cout << '\n';
    }
    return 0;
}

