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
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
	cin >> A[i];
    }
    sort(A.begin(), A.end());
    int i = 0;
    for(int j = i + 1; j < n; j++){
	if(A[j] > A[i]){
	    A[i] = -1;
	    i++;
	}
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
	if(A[i] > 0){
	    cnt++;
	}
    }
    cout << cnt << '\n';

    return 0;
}

